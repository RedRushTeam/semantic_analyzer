﻿#pragma once
#include "Singleton.h"

vector<fs::path> get_input_texts() {
	auto input_path = TEXTS_PATH/*fs::current_path()/"inputfiles"*/;
	fs::recursive_directory_iterator begin(input_path);
	fs::recursive_directory_iterator end;
	std::vector<fs::path> txtFiles;
	std::copy_if(begin, end, std::back_inserter(txtFiles), [](const fs::path& path) {
		return fs::is_regular_file(path) && (path.extension() == ".txt" || path.extension() == ".TXT"); });
	return txtFiles;
}

void out_matrix() {

	ofstream matrix("matrix.txt");

	for (auto some_scary_thing : Singleton::initialization().get_vec_of_hard_container_class()) {

		for (int i = 0; i < some_scary_thing.get_counter_of_tokenizer(); ++i)
			for (int j = 0; j < some_scary_thing.get_counter_of_tokenizer(); ++j)
			{
				if (i != 0 && j != 0 && i <= j) {
					matrix << endl << endl << i << " " << j << endl;
					for (int l = -GAP - 1; l <= GAP; ++l)
						matrix << some_scary_thing[i][j][l] << " ";
				}
			}
	}

	matrix.close();
}

void withdraw_list_of_string(list<string>& _list, string& _label) {
	cout << endl << endl << _label << endl << endl;

	for (auto obj : _list)
		cout << " " << obj;

}

int main(int argc, char* argv[])
{
	Eigen::setNbThreads(4);

	fs::remove("dictionary.txt");

	auto start = clock();
	setlocale(LC_ALL, "Russian");

	/*MEMORYSTATUSEX statex;

	statex.dwLength = sizeof(statex);

	GlobalMemoryStatusEx(&statex);

	cout << "There are " << statex.ullTotalPhys / 1024 << " total KB of physical memory." << endl << endl;

	cout << "There are " << statex.ullTotalPageFile / 1024 << " total KB of paging file." << endl << endl;*/

	const char* dict_path = NULL;
	const char* language = "russian";

	if (dict_path == NULL)
		dict_path = LEMADR;

	int flags = LEME_DEFAULT;

	printf("Loading the lemmatizator from %s\n", dict_path);

	HLEM hEngine = sol_LoadLemmatizatorA(dict_path, flags);

	if (hEngine == NULL)
	{
		printf("Could not load the lemmatizator from %s\n", dict_path);
		exit(1);
	}
	auto vector_of_texts = get_input_texts();

	cout << endl << "Найдено текстов: " << vector_of_texts.size() << endl;

	Singleton::initialization().set_parser(new parser);
	Singleton::initialization().set_hEngine(hEngine);
	Singleton::initialization().set_analyzer(new analyzer);

	int counter_of_text = 1;

	for (auto i : vector_of_texts)
		Singleton::initialization().prepare_data_with_link_for_text(i);

	Singleton::initialization().calculate_max_cont_size();

	cout << endl << "Calculating SVD matrix...";
	Singleton::initialization().calculate_SVD_matrix();

	cout << endl << "Calculating Singular Value...";
	auto svalues_as_vectorXF = Singleton::initialization().calculate_Singular_Value();
	MatrixXf* svalues_as_MatrixXf = new MatrixXf();
	svalues_as_MatrixXf->resize(svalues_as_vectorXF.size(), svalues_as_vectorXF.size());
	svalues_as_MatrixXf->fill(0.);

	for (int i = 0; i < svalues_as_vectorXF.size(); ++i)
		svalues_as_MatrixXf->operator()(i, i) = svalues_as_vectorXF[i];

	cout << endl << endl << "SVALUES MatrixXf:" << endl << *svalues_as_MatrixXf;

	svalues_as_MatrixXf->conservativeResize(GAP, GAP);

	cout << endl << endl << "Resized SVALUES MatrixXf:" << endl << *svalues_as_MatrixXf;

	MatrixXf U_matrix_as_matrixXF = Singleton::initialization().get_singular_U_matrix();

	MatrixXf V_matrix_as_matrixXF = Singleton::initialization().get_singular_V_matrix();

	MatrixXf* resized_V_matrix_as_matrixXF = new MatrixXf();
	resized_V_matrix_as_matrixXF->resize(GAP, V_matrix_as_matrixXF.cols());

	MatrixXf* resized_U_matrix_as_matrixXF = new MatrixXf();
	resized_U_matrix_as_matrixXF->resize(U_matrix_as_matrixXF.rows(), GAP);


	for (int i = 0; i < GAP; ++i)
		for (int j = 0; j < V_matrix_as_matrixXF.cols(); ++j)
			resized_V_matrix_as_matrixXF->operator()(i, j) = V_matrix_as_matrixXF(i, j);

	for (int i = 0; i < U_matrix_as_matrixXF.rows(); ++i)
		for (int j = 0; j < GAP; ++j)
			resized_U_matrix_as_matrixXF->operator()(i, j) = U_matrix_as_matrixXF(i, j);

	auto result_matrix = *resized_U_matrix_as_matrixXF * *svalues_as_MatrixXf;
	auto final_matrix = result_matrix * *resized_V_matrix_as_matrixXF;

	//cout << endl << endl << "RESULT MatrixXf:" << endl << final_matrix;

	vector<float> lens;
	lens.resize(final_matrix.rows(), 0);
	

	for (auto i = 0; i < final_matrix.rows(); ++i) {
		for (auto j = 0; j < final_matrix.cols(); ++j) {
			lens[i] = lens[i] + pow(final_matrix.operator()(i, j), 2);
		}
		lens[i] = sqrt(lens[i]);
	}

	/*for (auto &x : lens)
		cout << endl << x;*/

	//cout << endl << final_matrix.operator()(0, 0)<<final_matrix.operator()(1, 0) <<final_matrix.operator()(0, 1)<< final_matrix.operator()(1, 1) <<final_matrix.operator()(0, 2)<< final_matrix.operator()(1, 2);
	float scalar_proizv = final_matrix.operator()(0, 0) * final_matrix.operator()(1,0)  + final_matrix.operator()(0, 1) * final_matrix.operator()(1, 1) + final_matrix.operator()(0, 2) * final_matrix.operator()(1, 2)
		+ final_matrix.operator()(0, 3) * final_matrix.operator()(1, 3) + final_matrix.operator()(0, 4) * final_matrix.operator()(1, 4) + final_matrix.operator()(0, 5) * final_matrix.operator()(1, 5)
		+ final_matrix.operator()(0, 6) * final_matrix.operator()(1, 6) + final_matrix.operator()(0, 7) * final_matrix.operator()(1, 7);

	auto cos12 = scalar_proizv / lens[0] / lens[1];
	auto ugol = acos(cos12);





	//cout << endl << endl << "V MatrixXf:" << endl << V_matrix_as_matrixXF;

	//cout << std::endl << "Calculating max size:";
	//Singleton::initialization().calculate_sample_mean();

	//cout << endl << "(1/4) Calculating mat ozid...";
	//Singleton::initialization().calculate_mat_ozidanie();

	//cout << endl << "(2/4) Calculating mat disp...";
	//Singleton::initialization().calculate_mat_disperse();

	//cout << endl << "(3/4) Calculating sredne kv otklonenie fixed...";
	//Singleton::initialization().calculate_sredne_kv_otklonenie_fixed();

	//cout << endl << "(4/4) Finding fluctuations...";
	//Singleton::initialization().clear(mat_otkl_);
	//Singleton::initialization().find_fluctuations();
	//Singleton::initialization().clear(mat_disperse_);

	/*cout << endl << "(5/5) Out chart...";
	Singleton::initialization().out_for_chart();*/


	auto finish = clock();
	cout << endl << endl << ">>> " << finish - start << " <<<" << endl;

	return 0;
}

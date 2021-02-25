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

	//рассчет общих коллокаций
	for (int i = 0; i < vector_of_texts.size(); ++i)
		if(i == 0)
			Singleton::initialization().prepare_data_in_container_class(i);
		else {
			Singleton::initialization().prepare_data_in_container_class(i);
			Singleton::initialization().pluse_concret_cont_class_into_zero_cont_class(i);
			Singleton::initialization().clear_concret_cont_class(i);
		}
	//////////////////////////////////////////////////////////////////////////////////////

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

	vector<float> lenghts_words_vector;
	lenghts_words_vector.resize(U_matrix_as_matrixXF.rows(), 0);


	for (auto i = 0; i < U_matrix_as_matrixXF.rows(); ++i) {
		for (auto j = 0; j < U_matrix_as_matrixXF.cols(); ++j) {
			lenghts_words_vector[i] += pow(U_matrix_as_matrixXF.operator()(i, j), 2);
		}
		lenghts_words_vector[i] = sqrt(lenghts_words_vector[i]);
	}

	vector<float> lenghts_texts_vector;
	lenghts_texts_vector.resize(V_matrix_as_matrixXF.rows(), 0); // возможно нужно транспонирование


	for (auto i = 0; i < V_matrix_as_matrixXF.rows(); ++i) {
		for (auto j = 0; j < V_matrix_as_matrixXF.cols(); ++j) {
			lenghts_texts_vector[i] += pow(V_matrix_as_matrixXF.operator()(i, j), 2); // возможно нужно транспонирование
		}
		lenghts_texts_vector[i] = sqrt(lenghts_texts_vector[i]);
	}

	/*for (auto &x : lenghts_texts_vector)
		cout << endl << x;*/


		//list<float> scalar_proizvs;
	map<pair<int, int>, float> scalar_proizv; // текст, документ, скалярное произведение

	for (auto k = 0; k < V_matrix_as_matrixXF.rows(); ++k)
		for (auto i = 0; i < U_matrix_as_matrixXF.rows(); ++i) {
			//scalar_proizv.insert(make_pair(make_pair(i, k), 0));
			for (auto j = 0; j < U_matrix_as_matrixXF.cols(); ++j) {

				scalar_proizv[make_pair(i, k)] = scalar_proizv[make_pair(i, k)] + (U_matrix_as_matrixXF(i, j) * V_matrix_as_matrixXF(k, j));
			}
		}
	map<pair<int, int>, float> cosinuses; // текст, документ, скалярное произведение

	for (int i = 0; i < lenghts_words_vector.size(); ++i)
		for (int j = 0; j < lenghts_texts_vector.size(); ++j)
			cosinuses[make_pair(i, j)] = scalar_proizv[make_pair(i, j)] / lenghts_words_vector[i] / lenghts_texts_vector[j];


	int c = count_if(cosinuses.begin(), cosinuses.end(), [](pair<pair<int, int>, float> i) {
		if (i.second > 1 || (i.second < -1))
			return true;
		else
			return false;
		});

	float delete_threshold = 0.;    //число, ниже которого синусы удаляются

	list<pair<int, int>> list_of_terms_will_be_deleted;

	for (auto& obj : cosinuses) {
		if (obj.second < delete_threshold)
			if (cosinuses.find(obj.first) != cosinuses.end())
				list_of_terms_will_be_deleted.push_back(obj.first);
	}

	for (auto& obj : list_of_terms_will_be_deleted) {
		cosinuses.erase(obj);
	}

	ofstream matrix("matrix_test.txt");

	auto map_shit = Singleton::initialization().get_analyzer()->get_map_of_tokens();

	for (auto& obj : cosinuses)
		for (auto it = map_shit.begin(); it != map_shit.end(); ++it)
			if (it->second == obj.first.first)
				matrix << it->first << " ";

	int blyadovka1 = 0;
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

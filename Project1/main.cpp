#pragma once
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

	string prev_word = "";
	map<int, string> swaped_map;

	for (auto& obj : map_shit)
		swaped_map.insert(make_pair(obj.second, obj.first));

	for (auto& obj : cosinuses)
		if (swaped_map.find(obj.first.first) != swaped_map.end())
			if (!(prev_word == (*(swaped_map.find(obj.first.first))).second)) {
				prev_word = (*(swaped_map.find(obj.first.first))).second;
				matrix << (*(swaped_map.find(obj.first.first))).second << " ";
			}
	scalar_proizv.clear();
	cosinuses.clear();
	list_of_terms_will_be_deleted.clear();
	map_shit.clear();
	lenghts_texts_vector.clear();
	lenghts_words_vector.clear();
	swaped_map.clear();

	cout << endl << endl << endl;

	matrix.close();

	cout << std::endl << "Calculating max size:";
	Singleton::initialization().calculate_sample_mean();

	cout << endl << "Calculating mat ozid...";
	Singleton::initialization().calculate_mat_ozidanie();

	cout << endl << "Calculating mat disp...";
	Singleton::initialization().calculate_mat_disperse();

	cout << endl << "Calculating sredne kv otklonenie fixed...";
	Singleton::initialization().calculate_sredne_kv_otklonenie_fixed();

	cout << endl << "Finding fluctuations...";
	Singleton::initialization().clear(mat_otkl_);
	Singleton::initialization().find_colloc_fluctuations();
	Singleton::initialization().clear(mat_disperse_);
	Singleton::initialization().clear(mat_ozid_);
	//Singleton::initialization().clear(sample_mean_all_);
	Singleton::initialization().clear(mat_otkl_fixed_);

	//рассчет свд с коллокациями

	Singleton::initialization().calculate_colloc_SVD();

	//////////////////////////////////////////////////////////////////////////////////////
	auto colloc_svalues_as_vectorXF = Singleton::initialization().calculate_colloc_Singular_Value();
	MatrixXf* colloc_svalues_as_MatrixXf = new MatrixXf();
	colloc_svalues_as_MatrixXf->resize(colloc_svalues_as_vectorXF.size(), colloc_svalues_as_vectorXF.size());
	colloc_svalues_as_MatrixXf->fill(0.);

	for (int i = 0; i < colloc_svalues_as_vectorXF.size(); ++i)
		colloc_svalues_as_MatrixXf->operator()(i, i) = colloc_svalues_as_vectorXF[i];

	cout << endl << endl << "Colloc SVALUES MatrixXf:" << endl << *colloc_svalues_as_MatrixXf;

	colloc_svalues_as_MatrixXf->conservativeResize(GAP, GAP);

	cout << endl << endl << "Colloc resized SVALUES MatrixXf:" << endl << *colloc_svalues_as_MatrixXf;

	MatrixXf U_colloc_matrix_as_matrixXF = Singleton::initialization().get_colloc_singular_U_matrix();

	MatrixXf V_colloc_matrix_as_matrixXF = Singleton::initialization().get_colloc_singular_V_matrix();

	MatrixXf* resized_V_colloc_matrix_as_matrixXF = new MatrixXf();
	resized_V_colloc_matrix_as_matrixXF->resize(GAP, V_colloc_matrix_as_matrixXF.cols());

	MatrixXf* resized_U_colloc_matrix_as_matrixXF = new MatrixXf();
	resized_U_colloc_matrix_as_matrixXF->resize(U_colloc_matrix_as_matrixXF.rows(), GAP);


	for (int i = 0; i < GAP; ++i)
		for (int j = 0; j < V_colloc_matrix_as_matrixXF.cols(); ++j)
			resized_V_matrix_as_matrixXF->operator()(i, j) = V_colloc_matrix_as_matrixXF(i, j);

	for (int i = 0; i < U_colloc_matrix_as_matrixXF.rows(); ++i)
		for (int j = 0; j < GAP; ++j)
			resized_U_colloc_matrix_as_matrixXF->operator()(i, j) = U_colloc_matrix_as_matrixXF(i, j);

	auto colloc_result_matrix = *resized_U_colloc_matrix_as_matrixXF * *colloc_svalues_as_MatrixXf;
	auto colloc_final_matrix = colloc_result_matrix * *resized_V_colloc_matrix_as_matrixXF;

	//cout << endl << endl << "RESULT MatrixXf:" << endl << final_matrix;

	vector<float> colloc_lenghts_words_vector;
	colloc_lenghts_words_vector.resize(U_colloc_matrix_as_matrixXF.rows(), 0);


	for (auto i = 0; i < U_colloc_matrix_as_matrixXF.rows(); ++i) {
		for (auto j = 0; j < U_colloc_matrix_as_matrixXF.cols(); ++j) {
			colloc_lenghts_words_vector[i] += pow(U_colloc_matrix_as_matrixXF.operator()(i, j), 2);
		}
		colloc_lenghts_words_vector[i] = sqrt(colloc_lenghts_words_vector[i]);
	}

	vector<float> colloc_lenghts_texts_vector;
	colloc_lenghts_texts_vector.resize(V_colloc_matrix_as_matrixXF.rows(), 0); // возможно нужно транспонирование


	for (auto i = 0; i < V_colloc_matrix_as_matrixXF.rows(); ++i) {
		for (auto j = 0; j < V_colloc_matrix_as_matrixXF.cols(); ++j) {
			colloc_lenghts_texts_vector[i] += pow(V_colloc_matrix_as_matrixXF.operator()(i, j), 2); // возможно нужно транспонирование
		}
		colloc_lenghts_texts_vector[i] = sqrt(colloc_lenghts_texts_vector[i]);
	}
	map<pair<pair<int, int>, int>, float> colloc_scalar_proizv; //терм, терм, документ, скалярное произведение		//тут большая грязь

	for (auto k = 0; k < V_colloc_matrix_as_matrixXF.rows(); ++k)
		for (auto i = 0; i < U_colloc_matrix_as_matrixXF.rows(); ++i) 
			for (auto j = 0; j < U_colloc_matrix_as_matrixXF.cols(); ++j)
					//это все одна строка
					colloc_scalar_proizv[make_pair(make_pair((*Singleton::initialization().get_helper_vec())[i].first, (*Singleton::initialization().get_helper_vec())[i].second), k)] = 
						colloc_scalar_proizv[make_pair(make_pair((*Singleton::initialization().get_helper_vec())[i].first, (*Singleton::initialization().get_helper_vec())[i].second), k)] + 
							(U_colloc_matrix_as_matrixXF(i, j) * V_colloc_matrix_as_matrixXF(k, j));	//прям жо сюда

	map<pair<pair<int, int>, int>, float> colloc_cosinuses; // терм, документ, скалярное произведение

	for (int i = 0; i < colloc_lenghts_words_vector.size(); ++i)
		for (int j = 0; j < colloc_lenghts_texts_vector.size(); ++j)
			//это все одна строка
			colloc_cosinuses[make_pair(make_pair((*Singleton::initialization().get_helper_vec())[i].first, (*Singleton::initialization().get_helper_vec())[i].second), j)] = 
				colloc_scalar_proizv[make_pair(make_pair((*Singleton::initialization().get_helper_vec())[i].first, (*Singleton::initialization().get_helper_vec())[i].second), j)] / 
					colloc_lenghts_words_vector[i] / colloc_lenghts_texts_vector[j];	//прям жо сюда

	list<pair<pair<int, int>, int>>colloc_list_of_terms_will_be_deleted;

	float colloc_delete_threshold = 0.0;    //число, ниже которого синусы удаляются

	for (auto& obj : colloc_cosinuses)
		if (obj.second < colloc_delete_threshold)
			colloc_list_of_terms_will_be_deleted.push_back(obj.first);

	for (auto& obj : colloc_list_of_terms_will_be_deleted)
		colloc_cosinuses.erase(obj);

	ofstream colloc_matrix("colloc_matrix_test.txt");

	auto map_shit_for_colloc = Singleton::initialization().get_analyzer()->get_map_of_tokens();

	map<int, string> swaped_map_for_colloc;

	for (auto& obj : map_shit_for_colloc)
		swaped_map_for_colloc.insert(make_pair(obj.second, obj.first));

	map_shit_for_colloc.clear();

	for(auto it = colloc_cosinuses.begin(); it != colloc_cosinuses.end(); ++it){
		if (swaped_map_for_colloc.find(it->first.first.first) != swaped_map_for_colloc.end())
			colloc_matrix << (*swaped_map_for_colloc.find(it->first.first.first)).second << " ";
		if (swaped_map_for_colloc.find(it->first.first.second) != swaped_map_for_colloc.end())
			colloc_matrix << (*swaped_map_for_colloc.find(it->first.first.second)).second << " ";
	}

	colloc_matrix.close();

	//////////////////////////////////////////////////////////////////////////////////////
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

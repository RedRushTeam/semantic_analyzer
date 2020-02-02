//#define LEMADR "C:\\Program Files (x86)\\RussianGrammaticalDictionary\\bin-windows\\lemmatizer.db"
//#define LEMADR "G:\\RGD\\RussianGrammaticalDictionary\\bin-windows\\lemmatizer.db"
#define LEMADR "C:\\RGD\\RussianGrammaticalDictionary\\bin-windows\\lemmatizer.db"
//#define LEMADR "C:\\Users\\fortunati\\Documents\\RussianGrammaticalDictionary\\bin-windows\\lemmatizer.db"
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#define _CRT_SECURE_NO_WARNINGS
//#include <experimental/filesystem>
#pragma once
#include "parser.h"
#include "Singleton.h"

vector<fs::path> get_input_texts() {
	auto input_path = fs::current_path()/"inputfiles";
	fs::recursive_directory_iterator begin(input_path);
	fs::recursive_directory_iterator end;
	std::vector<fs::path> txtFiles;
	std::copy_if(begin, end, std::back_inserter(txtFiles), [](const fs::path& path) {
		return fs::is_regular_file(path) && (path.extension() == ".txt"); });
	return txtFiles;
}

void foo_for_sample_meal_thread() {
	Singleton::initialization().calculate_sample_mean();
}

void foo_for_asymmetry_coefficient_thread() {
	Singleton::initialization().calculate_asymmetry_coefficient();
}

void foo_for_for_excess_ratio_thread() {
	Singleton::initialization().calculate_excess_ratio();
}

void foo_for_calculate_sredne_kv_otklonenie() {
	Singleton::initialization().calculate_sredne_kv_otklonenie();
}

void foo_for_calculate_sredne_kv_otklonenie_fixed() {
	Singleton::initialization().calculate_sredne_kv_otklonenie_fixed();
}

list<string> parse_text(fs::path input_txt) {

	parser _parser(input_txt);
	return _parser.parse();
}

list<string> lemmatize_text(list<string> &list_of_parsed_symbols, HLEM &hEngine) {
	
	char utf9[512];

	list<string> list_of_lemmatized_words;

	for (string obj : list_of_parsed_symbols) {
		auto is_lemmas_if_good = sol_GetLemmaA(hEngine, obj.c_str(), utf9, sizeof(utf9));
		list_of_lemmatized_words.push_back(utf9);
	}

	return list_of_lemmatized_words;
}

int analyze_text(list<string> &list_of_lemmatized_words) {

	analyzer _analyzer(&list_of_lemmatized_words);
	_analyzer.set_k(GAP);
	_analyzer.shape_vec_of_tokens();
	_analyzer.shape_vec_tokens_of_text();
	_analyzer.give_space();
	_analyzer.analyze_vec_of_tokens();
	_analyzer.update_dictionary();

	Singleton::initialization().push_container(_analyzer.get_container_class());

	return _analyzer.get_counter_of_tokenizer();
}

void out_matrix() {

	ofstream matrix("matrix.txt");

	for (auto some_scary_thing : Singleton::initialization().get_list_of_container_class()) {

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

int main(int argc, char* argv[])
{
	auto start = clock();
	setlocale(LC_ALL, "Russian");

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

	int counter_of_tokenizer = 0;

	for (auto i : vector_of_texts) {
		auto list_of_parsed_symbols = parse_text(i);
		list<string> list_of_lemmatized_words = lemmatize_text(list_of_parsed_symbols, hEngine);
		list_of_parsed_symbols.clear();
		counter_of_tokenizer = analyze_text(list_of_lemmatized_words);
		list_of_lemmatized_words.clear();
	}
	//auto list_of_parsed_symbols1 = parse_text("input_text1.txt");

	/*cout << endl << endl << "\t\t\t\t***** Распарсеный текст номер 1 *****" << endl << endl;

	for (auto obj1 : list_of_parsed_symbols)
		cout << " " << obj1;

	cout << endl << "\t\t\t\t***** Распарсеный текст номер 2 *****" << endl << endl;

	for (auto obj1 : list_of_parsed_symbols1)
		cout << " " << obj1;*/

	//list<string> list_of_lemmatized_words = lemmatize_text(list_of_parsed_symbols, hEngine);
	//list<string> list_of_lemmatized_words1 = lemmatize_text(list_of_parsed_symbols1, hEngine);

	//list_of_parsed_symbols.clear();
	//list_of_parsed_symbols1.clear();

	/*cout << endl << "\t\t\t\t***** Лемматизированный текст номер 1 *****" << endl << endl;

	for (string obj : list_of_lemmatized_words)
		cout << " " << obj;

	cout << endl << "\t\t\t\t***** Лемматизированный текст номер 2 *****" << endl << endl;

	for (string obj : list_of_lemmatized_words1)
		cout << " " << obj;*/

	//int counter_of_tokenizer = 0;

	/*thread tr_for_analyze([&]() {counter_of_tokenizer = analyze_text(list_of_lemmatized_words); });
	thread tr_for_analyze1([&]() {counter_of_tokenizer = analyze_text(list_of_lemmatized_words1); });

	tr_for_analyze.join();
	tr_for_analyze1.join();

	tr_for_analyze.~thread();
	tr_for_analyze1.~thread();

	list_of_lemmatized_words.clear();
	list_of_lemmatized_words1.clear();*/

	thread tr_for_out(out_matrix);
	
							//6c

	Singleton::initialization().sinchronize_terms();	//10c
	Singleton::initialization().give_space();			//8c

	thread tr_for_sample_mean(foo_for_sample_meal_thread);

	Singleton::initialization().calculate_mat_ozidanie();	//16c
	Singleton::initialization().calculate_mat_disperse();	//26c

	thread tr_for_sredne_kv_otklonenie(foo_for_calculate_sredne_kv_otklonenie);
	thread tr_for_sredne_kv_otklonenie_fixed(foo_for_calculate_sredne_kv_otklonenie_fixed);

	tr_for_sredne_kv_otklonenie.detach();
	tr_for_sample_mean.join();
	tr_for_sredne_kv_otklonenie_fixed.join();

	thread tr_for_params_for_charts([&]() {
		Singleton::initialization().clear(mat_otkl_);
		Singleton::initialization().calculate_params_for_charts();
		Singleton::initialization().find_fluctuations();
		Singleton::initialization().clear(mat_ozid_);
		Singleton::initialization().clear(mat_disperse_);
		});

	thread tr_for_asymmetry_coefficient(foo_for_asymmetry_coefficient_thread);
	thread tr_for_excess_ratio(foo_for_for_excess_ratio_thread);
	tr_for_asymmetry_coefficient.join();
	tr_for_excess_ratio.join();

	tr_for_sredne_kv_otklonenie_fixed.~thread();
	tr_for_sredne_kv_otklonenie.~thread();
	tr_for_asymmetry_coefficient.~thread();
	tr_for_excess_ratio.~thread();
	tr_for_sample_mean.~thread();

	tr_for_params_for_charts.join();
	tr_for_params_for_charts.~thread();

	tr_for_out.join();
	tr_for_out.~thread();

	Singleton::initialization().out_for_chart();

	auto finish = clock();							//2.53	//2.30	//2.10	//2.0	//1.02 flag /Ox
	cout << endl << endl << ">>> " << finish - start << " <<<" << endl;

	return 0;
}

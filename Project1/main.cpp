#define LEMADR "C:\\RGD\\RussianGrammaticalDictionary\\bin-windows64\\lemmatizer.db"
#define TEXTS_PATH "C:\\Users\\fortunati\\Desktop\\Новая папка (2)"
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "parser.h"
#include "Singleton.h"
#include <lemmatizator_engine.h>

vector<fs::path> get_input_texts() {
	auto input_path = TEXTS_PATH/*fs::current_path()/"inputfiles"*/;
	fs::recursive_directory_iterator begin(input_path);
	fs::recursive_directory_iterator end;
	std::vector<fs::path> txtFiles;
	std::copy_if(begin, end, std::back_inserter(txtFiles), [](const fs::path& path) {
		return fs::is_regular_file(path) && (path.extension() == ".txt"); });
	return txtFiles;
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

void withdraw_list_of_string(list<string>& _list, string& _label) {
	cout << endl << endl << _label << endl << endl;

	for (auto obj : _list)
		cout << " " << obj;

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

	int counter_of_text = 1;

	cout << endl << "Найдено текстов: " << vector_of_texts.size() << endl;


	for (auto i : vector_of_texts)
		std::cout << i << std::endl;

	for (auto i : vector_of_texts) {


		//string _str_label_parse = "\t\t\t\t***** Распарсеный текст номер " + to_string(counter_of_text) + " *****";
		//string _str_label_lemmas = "\t\t\t\t***** Лемматизированный текст номер " + to_string(counter_of_text) + " *****";
		list<string> list_of_parsed_symbols = parse_text(i);
		//(list_of_parsed_symbols, _str_label_parse);
		list<string> list_of_lemmatized_words = lemmatize_text(list_of_parsed_symbols, hEngine);
		//withdraw_list_of_string(list_of_lemmatized_words, _str_label_lemmas);
		list_of_parsed_symbols.clear();
		analyze_text(list_of_lemmatized_words);
		list_of_lemmatized_words.clear();
		++counter_of_text;
	}

	thread tr_for_out(out_matrix);

	Singleton::initialization().sinchronize_terms();
	Singleton::initialization().give_space();

	thread tr_for_sample_mean([]() {
		Singleton::initialization().calculate_sample_mean();
		});

	Singleton::initialization().calculate_mat_ozidanie();
	Singleton::initialization().calculate_mat_disperse();

	thread tr_for_sredne_kv_otklonenie([]() {
		Singleton::initialization().calculate_sredne_kv_otklonenie();
		});
	thread tr_for_sredne_kv_otklonenie_fixed([]() {
		Singleton::initialization().calculate_sredne_kv_otklonenie_fixed();
		});

	tr_for_sredne_kv_otklonenie.detach();
	tr_for_sample_mean.join();
	tr_for_sredne_kv_otklonenie_fixed.join();

	thread tr_for_params_for_charts([&]() {
		Singleton::initialization().clear(mat_otkl_);
		Singleton::initialization().calculate_params_for_charts();
		Singleton::initialization().find_fluctuations();
		Singleton::initialization().clear(mat_disperse_);
		});

	thread tr_for_asymmetry_coefficient([]() {
		Singleton::initialization().calculate_asymmetry_coefficient();
		});
	thread tr_for_excess_ratio([]() {
		Singleton::initialization().calculate_excess_ratio();
		});
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

	auto finish = clock();							//2.53	//2.30	//2.10	//2.0	//1.02 flag /Ox	//strange 12sec
	cout << endl << endl << ">>> " << finish - start << " <<<" << endl;

	return 0;
}

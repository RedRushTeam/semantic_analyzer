//#define LEMADR "C:\\Program Files (x86)\\RussianGrammaticalDictionary\\bin-windows\\lemmatizer.db"
//#define LEMADR "G:\\RGD\\RussianGrammaticalDictionary\\bin-windows\\lemmatizer.db"
#define LEMADR "C:\\RGD\\RussianGrammaticalDictionary\\bin-windows\\lemmatizer.db"
//#define LEMADR "C:\\Users\\fortunati\\Documents\\RussianGrammaticalDictionary\\bin-windows\\lemmatizer.db"
#define _CRT_SECURE_NO_WARNINGS

#include "parser.h"
#include "Singleton.h"

using namespace std;

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

void foo_for_prepare_data_for_mat_ozid() {
	Singleton::initialization().prepare_data_for_mat_ozid();
}

void foo_for_prepare_data_for_mat_disperse() {
	Singleton::initialization().prepare_data_for_mat_disperse();
}

list<string> parse_text(string input_txt) {

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

void out_matrix(int counter_of_tokenizer) {

	ofstream matrix("matrix.txt");

	for (auto some_scary_thing : Singleton::initialization().get_list_of_container_class()) {

		for (int i = 0; i < counter_of_tokenizer; ++i)
			for (int j = 0; j < counter_of_tokenizer; ++j)
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

	auto list_of_parsed_symbols = parse_text("Readme.txt");
	auto list_of_parsed_symbols1 = parse_text("0101.txt");

	cout << endl << endl << "\t\t\t\t***** ����������� ����� ����� 1 *****" << endl << endl;

	for (auto obj1 : list_of_parsed_symbols)
		cout << " " << obj1;

	cout << endl << "\t\t\t\t***** ����������� ����� ����� 2 *****" << endl << endl;

	for (auto obj1 : list_of_parsed_symbols1)
		cout << " " << obj1;

	list<string> list_of_lemmatized_words = lemmatize_text(list_of_parsed_symbols, hEngine);
	list<string> list_of_lemmatized_words1 = lemmatize_text(list_of_parsed_symbols1, hEngine);

	list_of_parsed_symbols.clear();
	list_of_parsed_symbols1.clear();

	cout << endl << "\t\t\t\t***** ����������������� ����� ����� 1 *****" << endl << endl;

	for (string obj : list_of_lemmatized_words)
		cout << " " << obj;

	cout << endl << "\t\t\t\t***** ����������������� ����� ����� 2 *****" << endl << endl;

	for (string obj : list_of_lemmatized_words1)
		cout << " " << obj;

	int counter_of_tokenizer = 0;

	thread tr_for_analyze([&]() {counter_of_tokenizer = analyze_text(list_of_lemmatized_words); });
	thread tr_for_analyze1([&]() {counter_of_tokenizer = analyze_text(list_of_lemmatized_words1); });

	tr_for_analyze.join();
	tr_for_analyze1.join();

	tr_for_analyze.~thread();
	tr_for_analyze1.~thread();

	list_of_lemmatized_words.clear();
	list_of_lemmatized_words1.clear();

	thread tr_for_out(out_matrix, counter_of_tokenizer);
	tr_for_out.detach();
							//6c

	Singleton::initialization().sinchronize_terms();	//10c
	Singleton::initialization().give_space();			//8c

	thread tr_for_sample_mean(foo_for_sample_meal_thread);
	thread tr_for_prepare_data_for_mat_ozid(foo_for_prepare_data_for_mat_ozid);
	thread tr_for_prepare_data_for_mat_disperse(foo_for_prepare_data_for_mat_disperse);
	////������
	tr_for_prepare_data_for_mat_ozid.join();
	//foo_for_prepare_data_for_mat_ozid();
	Singleton::initialization().calculate_mat_ozidanie();	//16c		//����������� ���� ���� ������� ���������� ���
	
	tr_for_prepare_data_for_mat_ozid.~thread();

	tr_for_prepare_data_for_mat_disperse.join();
	//foo_for_prepare_data_for_mat_disperse();
	Singleton::initialization().calculate_mat_disperse();	//26c		//��������/�������� ������ "� ���" ����� ������� �������������� ���������
	tr_for_prepare_data_for_mat_disperse.~thread();

	thread tr_for_sredne_kv_otklonenie(foo_for_calculate_sredne_kv_otklonenie);		//85c	//68�	//58?	//70??????
	thread tr_for_sredne_kv_otklonenie_fixed(foo_for_calculate_sredne_kv_otklonenie_fixed);
	
	tr_for_sredne_kv_otklonenie.detach();
	tr_for_sample_mean.join();
	tr_for_sredne_kv_otklonenie_fixed.join();

	thread tr_for_asymmetry_coefficient(foo_for_asymmetry_coefficient_thread);
	thread tr_for_excess_ratio(foo_for_for_excess_ratio_thread);
	tr_for_asymmetry_coefficient.join();
	tr_for_excess_ratio.join();

	tr_for_sredne_kv_otklonenie_fixed.~thread();
	tr_for_sredne_kv_otklonenie.~thread();
	tr_for_asymmetry_coefficient.~thread();
	tr_for_excess_ratio.~thread();
	tr_for_sample_mean.~thread();
	tr_for_out.~thread();

	Singleton::initialization().out_for_chart();			//20c

	auto finish = clock();							//2.53	//2.30	//2.10
	cout << endl << endl << ">>> " << finish - start << " <<<" << endl;

	return 0;
}

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

int main(int argc, char* argv[])
{
	auto start = clock();
	setlocale(LC_ALL, "Russian");

	FILE* out = fopen("errors.txt", "wt");
	if (out == NULL)
	{
		printf("Can not open 'errors.txt' file for writing\n");
		exit(1);
	}

	const char* dict_path = NULL;

	bool check_model = false;
	const char* lemmas2_filename = "lemmas2.txt";
	const char* lemmas1_filename = "lemmas1.txt";
	const char* language = "russian";

	if (dict_path == NULL)
		dict_path = LEMADR;

		int flags = 0;

		flags = LEME_DEFAULT;

		printf("Loading the lemmatizator from %s\n", dict_path);

		HLEM hEngine = sol_LoadLemmatizatorA(dict_path, flags);

		if (hEngine == NULL)
		{
			printf("Could not load the lemmatizator from %s\n", dict_path);
			exit(1);
		}

			string input_txt = "Readme.txt";
			string input_txt1 = "0101.txt";
			parser _parser(input_txt);
			parser _parser1(input_txt1);

			auto list_of_parsed_symbols = _parser.parse();
			auto list_of_parsed_symbols1 = _parser1.parse();
			for (auto obj1 : list_of_parsed_symbols)
				cout << " " << obj1;

			list<string> list_of_lemmatized_words;
			list<string> list_of_lemmatized_words1;


			char utf9[512];

			int i = 0;
			int unleemed = 0;
			for (string obj : list_of_parsed_symbols) {
				auto is_lemmas_if_good = sol_GetLemmaA(hEngine, obj.c_str(), utf9, sizeof(utf9));
				list_of_lemmatized_words.push_back(utf9);
			}
			for (string obj : list_of_parsed_symbols1) {
				auto is_lemmas_if_good = sol_GetLemmaA(hEngine, obj.c_str(), utf9, sizeof(utf9));
				list_of_lemmatized_words1.push_back(utf9);
			}

			cout << endl << endl;
			for (string obj : list_of_lemmatized_words)
				cout << " " << obj;

			sol_DeleteLemmatizator(hEngine);

			analyzer _analyzer1(&list_of_lemmatized_words1);
			_analyzer1.set_k(GAP);
			_analyzer1.shape_vec_of_tokens();
			_analyzer1.shape_vec_tokens_of_text();
			_analyzer1.give_space();
			_analyzer1.analyze_vec_of_tokens();
			Singleton::initialization().push_container(_analyzer1.get_container_class());
			_analyzer1.update_dictionary();
			analyzer _analyzer(&list_of_lemmatized_words);
			_analyzer.set_k(GAP);
			_analyzer.shape_vec_of_tokens();
			_analyzer.shape_vec_tokens_of_text();
			_analyzer.give_space();
			_analyzer.analyze_vec_of_tokens();
			
			Singleton::initialization().push_container(_analyzer.get_container_class());

			_analyzer.~analyzer();
			_analyzer1.~analyzer();

			Singleton::initialization().sinchronize_terms();
			Singleton::initialization().give_space();

			thread tr_for_sample_mean(foo_for_sample_meal_thread);

			Singleton::initialization().calculate_mat_ozidanie();
			Singleton::initialization().calculate_mat_disperse();

			Singleton::initialization().calculate_sredne_kv_otklonenie();		//������ 
			Singleton::initialization().calculate_sredne_kv_otklonenie_fixed(); //������

			tr_for_sample_mean.join();

			thread tr_for_asymmetry_coefficient(foo_for_asymmetry_coefficient_thread);
			thread tr_for_excess_ratio(foo_for_for_excess_ratio_thread);
			tr_for_asymmetry_coefficient.join();
			tr_for_excess_ratio.join();

			tr_for_asymmetry_coefficient.~thread();
			tr_for_excess_ratio.~thread();
			tr_for_sample_mean.~thread();

			//1.53 �� ���������� ����� � � ��������	//2.40 ���
			Singleton::initialization().out_for_chart();			//����� ����� =50+�		

			ofstream matrix("matrix.txt");
			auto _list_of_container_class = Singleton::initialization().get_list_of_container_class();
			for (auto some_scary_thing : _list_of_container_class) {

				for (int i = 0; i < _analyzer.get_counter_of_tokenizer(); ++i)
					for (int j = 0; j < _analyzer.get_counter_of_tokenizer(); ++j)
					{
						if (i != 0 && j != 0 && i <= j) {
							matrix << endl << endl << i << " " << j << endl;
							for (int l = -GAP - 1; l <= GAP; ++l)
								matrix << some_scary_thing[i][j][l] << " ";
						}
					}
			}

		cout << endl;

		fclose(out);

		auto finish = clock();
		cout << endl << ">>> " << finish - start << " <<<";

		return 0;
}

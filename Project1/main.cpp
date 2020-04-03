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

	MEMORYSTATUSEX statex;

	statex.dwLength = sizeof(statex);

	GlobalMemoryStatusEx(&statex);

	cout << "There are " << statex.ullTotalPhys / 1024 << " total KB of physical memory." << endl << endl;

	cout << "There are " << statex.ullTotalPageFile / 1024 << " total KB of paging file." << endl << endl;

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

	Singleton::initialization().calculate_sample_mean();

	Singleton::initialization().calculate_mat_ozidanie();

	Singleton::initialization().calculate_mat_disperse();

	Singleton::initialization().calculate_sredne_kv_otklonenie_fixed();

	Singleton::initialization().clear(mat_otkl_);
	Singleton::initialization().find_fluctuations();
	Singleton::initialization().clear(mat_disperse_);

	Singleton::initialization().out_for_chart();

	auto finish = clock();
	cout << endl << endl << ">>> " << finish - start << " <<<" << endl;

	return 0;
}

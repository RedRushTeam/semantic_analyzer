#pragma once
#include "container_class.h"

class analyzer
{
public:
	analyzer() {}
	analyzer(std::list<std::string>* list_of_all_parsed_text) : list_of_all_parsed_text(list_of_all_parsed_text) {}

	bool is_index_valid(int ind) const;

	void analyze_vec_of_tokens();

	container_class get_container_class();

	void shape_vec_of_tokens();

	void shape_vec_tokens_of_text();

	int get_k();

	int get_counter_of_tokenizer();

	void set_k(int _k);

	void give_space();

	std::map<std::string, int> get_map_of_tokens();

	void set_map_of_tokens(string dictionary_file);

	void update_dictionary();

	~analyzer() {
		vec_of_tokens.~vector();
		this->update_dictionary();
	}

private:
	vector<int> vec_of_tokens;
	container_class _container_class;
	int k;
	int counter_of_tokenizer;
	std::list<std::string>* list_of_all_parsed_text;
	std::map<std::string, int> map_of_tokens;
};
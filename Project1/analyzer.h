#pragma once
#include "hard_container_class.h"

class analyzer
{
public:
	analyzer() {}
	analyzer(std::list<std::string>* list_of_all_parsed_text) : list_of_all_parsed_text(list_of_all_parsed_text) { 
		_container_class = new hard_container_class;
	}

	analyzer(container_class_interface* _container_class_interface, std::list<std::string>* list_of_all_parsed_text) : list_of_all_parsed_text(list_of_all_parsed_text), _container_class(_container_class_interface)	{}

	bool is_index_valid(int ind) const;

	void analyze_vec_of_tokens();

	container_class_interface* get_container_class();

	void shape_vec_of_tokens();

	void shape_vec_tokens_of_text();

	int get_k();

	int get_counter_of_tokenizer();

	void set_list_of_all_parsed_text(std::list<std::string>* list_of_all_parsed_text);

	void set_k(char _k);

	void set_container_class(container_class_interface* _container_class);

	void give_space();

	std::map<std::string, int> get_map_of_tokens();

	void set_map_of_tokens(string dictionary_file);

	void update_dictionary();

	void upload_data();

	void clear();

	~analyzer() {
		vec_of_tokens.~vector();
		this->update_dictionary();
		list_of_all_parsed_text->clear();
		delete list_of_all_parsed_text;
	}

private:
	vector<int> vec_of_tokens;
	container_class_interface* _container_class;
	char k;
	int counter_of_tokenizer;
	std::list<std::string>* list_of_all_parsed_text;
	std::map<std::string, int> map_of_tokens;
};
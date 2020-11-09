#pragma once
#include "sparce_container_class.h"
//#include "parser.h"

class analyzer
{
public:
	analyzer() {}
	analyzer(std::list<std::string> list_of_all_parsed_text) : list_of_all_parsed_text(list_of_all_parsed_text) { 
		_container_class = new hard_container_class;
		//_container_class->give_space()
	}

	analyzer(super_container_class* _hard_container_class, std::list<std::string> list_of_all_parsed_text) : list_of_all_parsed_text(list_of_all_parsed_text), _container_class(_hard_container_class)	{}

	bool is_index_valid(int ind) const;

	void analyze_vec_of_tokens();

	super_container_class* get_container_class();

	void shape_vec_of_tokens();

	void shape_vec_tokens_of_text();

	int get_k();

	int get_counter_of_tokenizer();

	void set_list_of_all_parsed_text(std::list<std::string> list_of_all_parsed_text);

	void set_k(char _k);

	void set_container_class(super_container_class* _container_class);

	void give_space(int maxsize);

	std::map<std::string, int> get_map_of_tokens();

	void set_map_of_tokens(string dictionary_file);

	void update_dictionary();

	void upload_data();

	void clear();

	~analyzer() {
		this->update_dictionary();
		vec_of_tokens.clear();
		list_of_all_parsed_text.clear();
		//delete list_of_all_parsed_text;
	}

	int size_for_give_space;

private:
	vector<int> vec_of_tokens;
	super_container_class* _container_class;
	char k;
	int counter_of_tokenizer;
	std::list<std::string> list_of_all_parsed_text;
	std::map<std::string, int> map_of_tokens;
	
};
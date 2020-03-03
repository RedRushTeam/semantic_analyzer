#include "analyzer.h"

void analyzer::analyze_vec_of_tokens()
{

	for (int j = 0; j < this->vec_of_tokens.size(); ++j) {

		if (this->vec_of_tokens[j] != STOP_WORD) {

			for (int i = j - 1; i >= j - this->k; --i) {

				if (this->is_index_valid(i)
					&& this->vec_of_tokens[i] != STOP_WORD) {
					this->_hard_container_class.increment(vec_of_tokens[j], vec_of_tokens[i], this->k - (j - i));
				}
			}

			for (int l = j + 1; l <= j + k && l < this->vec_of_tokens.size(); ++l) {

				if (this->is_index_valid(l) && this->vec_of_tokens[l] != STOP_WORD)
					this->_hard_container_class.increment(vec_of_tokens[j], vec_of_tokens[l], (this->k + 1) - (j - l));
			}
		}
	}

	_hard_container_class.counter_of_tokenizer = this->counter_of_tokenizer;

}

hard_container_class analyzer::get_hard_container_class()
{
	return _hard_container_class;
}

bool analyzer::is_index_valid(int ind) const
{
	if (ind < 0)
		return false;

	return true;
}

void analyzer::shape_vec_of_tokens()
{
	this->set_map_of_tokens("dictionary.txt");
	int i = map_of_tokens.size() + 1;
	if (map_of_tokens.empty()) {
		this->map_of_tokens["À"] = 0;
	}
	for (auto obj : *this->list_of_all_parsed_text)
		if (map_of_tokens.find(obj) == map_of_tokens.end()) {
			map_of_tokens[obj] = i;
			i++;
		}

	this->counter_of_tokenizer = i;
}

void analyzer::shape_vec_tokens_of_text()
{
	std::vector<int> vec_tokens_of_text;
	vec_tokens_of_text.reserve(list_of_all_parsed_text->size());
	for (auto obj : *this->list_of_all_parsed_text) {
		auto ptr = map_of_tokens.find(obj);
		vec_tokens_of_text.push_back(ptr->second);
	}

	this->vec_of_tokens = vec_tokens_of_text;
}

void analyzer::give_space() 
{
	_hard_container_class.give_space(counter_of_tokenizer, k);
}

int analyzer::get_counter_of_tokenizer() {
	return this->counter_of_tokenizer;
}

void analyzer::set_k(int _k) {
	k = _k;
}

int analyzer::get_k() {
	return this->k;
}

std::map<std::string, int> analyzer::get_map_of_tokens() {
	return map_of_tokens;
}

void analyzer::set_map_of_tokens(string dictoinary_file) {
	ifstream dic(dictoinary_file);
	string line, sub1, sub2;
	if (dic.is_open()) {
		getline(dic, line);
	}
	if (dic.is_open()) {
		while (!dic.eof()) {
			getline(dic, line);
			sub1 = line.substr(0, line.find(' '));
			sub2 = line.substr(line.find(' ') + 1, line.size());
			this->map_of_tokens[sub1] = stoi(sub2);
		}
	}
}

void analyzer::update_dictionary()
{
	ofstream dict("dictionary.txt");
	for (auto it : this->get_map_of_tokens()) {
		dict << endl << it.first << " " << it.second;
	}
}
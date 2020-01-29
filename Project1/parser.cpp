#include "parser.h"


list<string> parser::parse()
{
	this->delete_trash();
	string text_all;
	//this->check_all_words(text_all);
	list<string> terms;
	char tmp;
	ifstream file("parced_"+ this->_filename);
	if (file.is_open()) {
		while (!file.eof()) {
			tmp = file.get();
			text_all.push_back(tmp);
		}
		text_all.push_back(' ');
	}
	else
		cout << endl << "filename is invalid!" << endl;

	string substring_word;
	while (!text_all.empty())
	{
		substring_word = text_all.substr(0, text_all.find(' '));
		text_all = text_all.substr(text_all.find(' ') + 1, text_all.size());
		if (stop_words.find(substring_word) == stop_words.end())
			terms.push_back(substring_word);
		else
			terms.push_back("а");
	}
	terms.back().pop_back();
	return terms;
}

void parser::check_all_words(string text)
{
	cout << endl << text << endl;
}

void parser::delete_trash()
{
	std::ifstream _input(_filename);
	std::ofstream _output("parced_" + this->_filename);
	int count = 1;
	int helper = 1;
	int size = 0;
	char tmp;
	std::string text;
	if (_input.is_open()) {
		while (!_input.eof()) {
			tmp = _input.get();
			text.push_back(tmp);
			size++;
		}
	}
	else
		cout << "it doesn't work";

	while (helper) {

		for (int i = 0; i < text.size(); i++) {
			helper = 0;
			if (text.find('\n') != text.npos) {
				helper++;
				text[text.find('\n')] = ' ';
			}
			if (text.find('\0') != text.npos) {
				helper++;
				text[text.find('\0')] = ' ';
			}
		}
	}
	while (count) {
		count = 0;
		for (auto i : stop_symbols) {
			auto searcher = text.find(i);
			if (searcher != text.npos) {
				count++;
				std::string tmp1, tmp2;
				tmp1 = text.substr(0, searcher);
				tmp2 = text.substr(searcher + 1, size);
				text = tmp1 + tmp2;
			}
		}
	}
	text.pop_back();//êîñòûëü
	_output << text;
}
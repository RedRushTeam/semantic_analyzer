#include "parser.h"


/*list<string> parser::parse()
{
	//this->delete_trash();					//Попался!
	string text_all;
	//this->check_all_words(text_all);
	list<string> terms = this->delete_trash();
	char tmp;
	ifstream file(this->_filename);
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
}*/

list<string> parser::parse() {
	auto terms = this->delete_trash();
	for (auto word : terms)
		if (stop_words.find(word) != stop_words.end())
			word="a";
	return terms;
}

void parser::set_filename(fs::path filename)
{
	this->_filename = filename;
}

void parser::check_all_words(string text)
{
	cout << endl << text << endl;
}

list<string> parser::delete_trash()
{
	std::ifstream _input(_filename);
	std::ofstream _output("RESULTOFPARSE.txt");
	int count = 1;
	int helper = 1;
	int size = 0;
	char tmp;
	regex no_letters("[^А-Яа-я -]");
	regex spaces(" {2,}");
	regex defis("\-[а-яА-Я]");
	regex post_defis("\[[а-яА-Я]-");
	regex un_defis("\- |\ -");
	string replacement = " ";
	string nothing = "";
	std::string untext;
	if (_input.is_open()) {
		while (!_input.eof()) {
			tmp = _input.get();
			untext.push_back(tmp);
			size++;
		}
	}
	else
		cout << "it doesn't work";

	string temp = regex_replace(untext, no_letters, nothing);
	string temp3 = regex_replace(temp, defis, nothing);
	if (TRASH_DELETE_OPTION) {
		string temp2 = regex_replace(temp3, post_defis, nothing);
		temp3 = regex_replace(temp2, un_defis, nothing);
		temp2.clear();
	}
	string text = regex_replace(temp3, spaces, replacement);
	

	transform(text.begin(), text.end(), text.begin(), tolower);;

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
		if (text[0] == ' ')
			text.erase(0, 1);
		text.pop_back();
		//text.push_back(' ');
		_output << text;
		string substring_word;
		list<string> terms;
		while (!text.empty())
		{
			substring_word = text.substr(0, text.find(' '));
			text = text.substr(text.find(' ') + 1, text.size());
			terms.push_back(substring_word);
		}
		//terms.back().pop_back();
		cout << ">>>>>>>>>" << terms.front() << "<<<<<<<<<<<<<<<<<<<<";
		temp.clear();
		temp3.clear();

		return terms;
}
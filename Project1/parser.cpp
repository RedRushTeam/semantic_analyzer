#include "parser.h"



list<string> parser::parse() {
	auto terms = this->delete_trash();
	for (auto &word : terms)
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
	//std::ofstream _output("RESULTOFPARSE.txt");
	int count = 1;
	int helper = 1;
	int size = 0;
	int tmp;

	regex no_letters("[^А-Яа-я -]");
	regex spaces("( {2,})");
	regex defis("(\ -[а-яА-Я])");

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

	string temp = regex_replace(untext, no_letters, replacement);
	string temp3 = regex_replace(temp, defis, nothing);
	string text = regex_replace(temp3, spaces, replacement);
	
	//string text = regex_replace(untext, (no_letters, defis, spaces), replacement);

	transform(text.begin(), text.end(), text.begin(), ::tolower);

	/*while (helper) {

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
	}*/
		if (text[0] == ' ')
			text.erase(0, 1);
		text.pop_back();
		if (text[text.size()-1]!=' ')
			text.push_back(' ');
		//_output << text;
		string substring_word;
		list<string> terms;

		while (!text.empty())
		{
			substring_word = text.substr(0, text.find(' '));
			text = text.substr(text.find(' ') + 1, text.size());
			terms.push_back(substring_word);
		}
		//temp.clear();
		//temp3.clear();

		return terms;
}
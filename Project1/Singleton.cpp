#include "Singleton.h"

Singleton& Singleton::initialization()
{
	static Singleton _singleton;
	return _singleton;
}

void Singleton::push_container(hard_container_class _container_class)
{
	this->vec_of_hard_container_class.push_back(_container_class);
}

vector<hard_container_class> Singleton::get_vec_of_hard_container_class() const
{
	return this->vec_of_hard_container_class;
}

int Singleton::get_length_of_all_hard_container_class() const
{
	int counter_of_all_elems = 0;
	for (auto obj_of_cont_class : this->vec_of_hard_container_class)
		for (auto first_index = 0; first_index < obj_of_cont_class.get_counter_of_tokenizer(); ++first_index)
			for (auto second_index = 0; second_index < obj_of_cont_class.get_counter_of_tokenizer(); ++second_index)
				for (auto third_index = -GAP - 1; third_index <= GAP; ++third_index)
					if (first_index <= second_index)
						++counter_of_all_elems;
	return counter_of_all_elems;
}

my_double Singleton::divider(int size) {
	int starter = 1;
	int finisher = size;
	auto sum = (starter + finisher) * (finisher - starter + 1) / 2;
	return sum;
}

void Singleton::calculate_sample_mean()
{
	this->sample_mean_all.give_space(this->max_cont_size, GAP);

	for (int i = 0; this->vec_of_hard_container_class.size() > i; ++i) {
		this->prepare_data_in_container_class(i);
		this->sample_mean_all += vec_of_hard_container_class[i];
		this->vec_of_hard_container_class[i].clear();
	}
	sample_mean_all = sample_mean_all / this->vec_of_hard_container_class.size();
}

void Singleton::calculate_mat_ozidanie()
{
	this->mat_ozidanie.give_space(this->max_cont_size, GAP);

	for (int i = 0; this->vec_of_hard_container_class.size() > i; ++i) {
		this->prepare_data_in_container_class(i);
		this->mat_ozidanie += vec_of_hard_container_class[i];
		this->vec_of_hard_container_class[i].clear();
	}

	this->mat_ozidanie = this->mat_ozidanie / this->divider(this->vec_of_hard_container_class.size() * (2 + 2 * GAP));
}

void Singleton::calculate_mat_disperse()
{
	this->mat_disperse.give_space(this->max_cont_size, GAP);

	for (int i = 0; this->vec_of_hard_container_class.size() > i; ++i) {
		this->prepare_data_in_container_class(i);
		this->mat_disperse += vec_of_hard_container_class[i].pow_all(2);
		vec_of_hard_container_class[i].clear();
	}

	this->mat_disperse = this->mat_disperse / this->divider(this->vec_of_hard_container_class.size() * (2 + 2 * GAP));

	this->mat_disperse = this->mat_disperse - this->mat_ozidanie.pow_all(2);
}

void Singleton::calculate_sredne_kv_otklonenie()
{
	
	this->sredne_kv_otklonenie.give_space(this->max_cont_size, GAP);

	this->sredne_kv_otklonenie = this->mat_disperse.pow_all(2);
}

void Singleton::calculate_sredne_kv_otklonenie_fixed()
{

	this->sredne_kv_otklonenie_fixed.give_space(this->max_cont_size, GAP);

	this->sredne_kv_otklonenie_fixed = this->mat_disperse * (this->vec_of_hard_container_class.size() / (this->vec_of_hard_container_class.size() - 1));
	//////������� ������� �� 0!!!!! ����� �� ������ ���� ����!!!

	this->sredne_kv_otklonenie_fixed = this->sredne_kv_otklonenie_fixed.sqrt_all();
}

void Singleton::calculate_asymmetry_coefficient()						//////todo//////
{

	this->asymmetry_coefficient.give_space(this->max_cont_size, GAP);

	for (int i = 0; this->vec_of_hard_container_class.size() > i; ++i) {
		this->prepare_data_in_container_class(i);
		this->asymmetry_coefficient += (vec_of_hard_container_class[i] - this->get_sample_mean_all()).pow_all(3);
		vec_of_hard_container_class[i].clear();
	}

	this->asymmetry_coefficient = (this->asymmetry_coefficient / this->vec_of_hard_container_class.size()) / this->get_sredne_kv_otklonenie_fixed().pow_all(3);
	/////zdes' ispolzovano ispravlennoe otklonenie!!!!!
}

void Singleton::calculate_excess_ratio()								//////todo//////
{

	this->excess_ratio.give_space(this->max_cont_size, GAP);

	for (int i = 0; this->vec_of_hard_container_class.size() > i; ++i) {
		this->prepare_data_in_container_class(i);
		this->excess_ratio += (vec_of_hard_container_class[i] - this->get_sample_mean_all()).pow_all(4);
		vec_of_hard_container_class[i].clear();
	}

	this->excess_ratio = (this->excess_ratio / this->vec_of_hard_container_class.size()) / this->get_sredne_kv_otklonenie_fixed().pow_all(4) - 3;
	/////����� �������� �������� ������� ������������ ������ �� ������������ �����, � ����� ������������� ������ ����
	/////zdes' ispolzovano ispravlennoe otklonenie!!!!!
}

hard_container_class Singleton::get_sredne_kv_otklonenie() const
{
	return this->sredne_kv_otklonenie;
}

hard_container_class Singleton::get_sredne_kv_otklonenie_fixed() const
{
	return this->sredne_kv_otklonenie_fixed;
}

hard_container_class Singleton::get_mat_ozidanie() const
{
	return this->mat_ozidanie;
}

hard_container_class Singleton::get_mat_disperse() const
{
	return this->mat_disperse;
}

hard_container_class Singleton::get_asymmetry_coefficient() const
{
	return this->asymmetry_coefficient;
}

hard_container_class Singleton::get_excess_ratio() const
{
	return this->excess_ratio;
}

hard_container_class Singleton::get_sample_mean_all() const
{
	return this->sample_mean_all;
}

bool Singleton::remove_hard_container_class(hard_container_class _hard_container_class)
{
	vector<hard_container_class>::iterator tmp = find(this->vec_of_hard_container_class.begin(), this->vec_of_hard_container_class.end(), _hard_container_class);
	if (tmp == this->vec_of_hard_container_class.end())
		return false;
	this->vec_of_hard_container_class.erase(tmp);
	return true;
}

void Singleton::find_fluctuations()	//TODO
{

	auto sum1 = this->calculate_parametr_to_one_term(this->mat_ozidanie) + this->calculate_parametr_to_one_term(this->sredne_kv_otklonenie_fixed);
	auto razn1 = this->calculate_parametr_to_one_term(this->mat_ozidanie) - this->calculate_parametr_to_one_term(this->sredne_kv_otklonenie_fixed);
	auto shhh1 = this->calculate_parametr_to_one_term(this->mat_ozidanie);

	hard_container_class chart1;
	chart1.give_space(this->max_cont_size, GAP);
	auto keks = this->max_cont_size;

	for (int i = 0; this->vec_of_hard_container_class.size() > i; ++i) {
		this->prepare_data_in_container_class(i);
		for (auto q = 0; q < keks; ++q)
			for (auto j = 0; j < keks; ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					chart1[q][q][p] = chart1[q][q][p] + this->vec_of_hard_container_class[i][q][j][p];
		vec_of_hard_container_class[i].clear();
	}

	chart1 = chart1 / vec_of_hard_container_class.size();
	analyzer helper;
	helper.set_map_of_tokens("dictionary.txt");
	ofstream ff("fluctuation.txt");
	for (int i = 1; i < chart1.get_counter_of_tokenizer(); i++)
		for (int l = -GAP - 1; l <= GAP; ++l)
			if ((chart1[i][i][l] > sum1[i][i][l]) || (chart1[i][i][l] < razn1[i][i][l])) {
				for (auto q : helper.get_map_of_tokens())
					if (q.second == i) {
						ff << q.first << " ";
						//i++;
						break;
					}
				break;
			}
}

void Singleton::clear(type_of_purpose_of_cont_class _type_of_cont_class)
{
	switch (_type_of_cont_class)
	{
	case mat_ozid_:
		this->mat_ozidanie.clear();
		break;
	case mat_disperse_:
		this->mat_disperse.clear();
		break;
	case mat_otkl_:
		this->sredne_kv_otklonenie.clear();
		break;
	case mat_otkl_fixed_:
		this->sredne_kv_otklonenie_fixed.clear();
		break;
	case excess_ratio_:
		this->excess_ratio.clear();
		break;
	case asymmetry_coefficient_:
		this->asymmetry_coefficient.clear();
		break;
	case sample_mean_all_:
		this->sample_mean_all.clear();
		break;
	default:
		nullptr;
		break;
	}
}

void Singleton::set_parser(parser* _parser)
{
	this->_parser = _parser;
}

void Singleton::set_analyzer(analyzer* _analyzer)
{
	this->_analyzer = _analyzer;
}

void Singleton::set_hEngine(HLEM& hEngine)
{
	this->hEngine = hEngine;
}


void Singleton::out_for_chart()	//TODO
{
	
	auto sum1 = this->calculate_parametr_to_one_term(this->mat_ozidanie) + this->calculate_parametr_to_one_term(this->sredne_kv_otklonenie_fixed);
	auto razn1 = this->calculate_parametr_to_one_term(this->mat_ozidanie) - this->calculate_parametr_to_one_term(this->sredne_kv_otklonenie_fixed);
	auto shhh1 = this->calculate_parametr_to_one_term(this->mat_ozidanie);

	hard_container_class chart1;
	chart1.give_space(this->max_cont_size, GAP);
	auto keks = this->max_cont_size;
	for (int i = 0; this->vec_of_hard_container_class.size() > i; ++i) {
		this->prepare_data_in_container_class(i);
		for (auto q = 0; q < keks; ++q)
			for (auto j = 0; j < keks; ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					chart1[q][q][p] = chart1[q][q][p] + this->vec_of_hard_container_class[i][q][j][p];
		vec_of_hard_container_class[i].clear();
	}

	chart1 = chart1 / vec_of_hard_container_class.size();

	//auto keks = this->vec_of_hard_container_class[this->vec_of_hard_container_class.size() - 1]->get_counter_of_tokenizer();

	ofstream to_chart("chart.txt");

		for (int i = 1; i < chart1.get_counter_of_tokenizer(); ++i)
			{
					to_chart << endl << endl << "term " << i << endl;
					for (int l = -GAP - 1; l <= GAP; ++l) 
						if(l==-GAP-1)
							to_chart << "really: " << chart1[i][i][l] << " ";
						else 
							to_chart << chart1[i][i][l] << " ";

					to_chart << endl;

					for (int l = -GAP - 1; l <= GAP; ++l)
						if (l == -GAP - 1)
							to_chart << "mat_ozhidanie: " << shhh1[i][i][l] << " ";
						else 
							to_chart << shhh1[i][i][l] << " ";

					to_chart << endl;

					for (int l = -GAP - 1; l <= GAP; ++l)
						if (l == -GAP - 1)
							to_chart << "mat_ozhidanie+otkl: " << sum1[i][i][l] << " ";
						else 
							to_chart << sum1[i][i][l] << " ";

					to_chart << endl;

					for (int l = -GAP - 1; l <= GAP; ++l)
						if (l == -GAP - 1)
							to_chart << "mat_ozhidanie-otkl: " << razn1[i][i][l] << " ";
						else 
							to_chart << razn1[i][i][l] << " ";	
		}
		to_chart.close();
}

void Singleton::sinchronize_terms()
{
	int max_size = this->max_cont_size;

	for (auto obj : this->vec_of_hard_container_class)
		obj.set_counter_of_tokenizer(max_size);
}

void Singleton::sinchronize_terms(hard_container_class _container_class)
{
	hard_container_class new_cont_class;
	new_cont_class.give_space(this->max_cont_size, _container_class.get_k());
	for (auto q = 0; q < _container_class.get_counter_of_tokenizer(); ++q)
		for (auto j = 0; j < _container_class.get_counter_of_tokenizer(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				new_cont_class[q][j][p] = _container_class[q][j][p];

}

hard_container_class Singleton::calculate_parametr_to_one_term(hard_container_class _parametr)
{
	for (auto q = 0; q < _parametr.get_counter_of_tokenizer(); ++q)
		for (auto j = 0; j < _parametr.get_counter_of_tokenizer(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				_parametr[q][q][p] += _parametr[q][j][p];
	return _parametr;
}

void Singleton::prepare_data_with_link_for_text(fs::path filename)
{
	hard_container_class tmp(GAP, hard_container_class_, filename);
	this->push_container(tmp);
}

void Singleton::prepare_data_in_container_class(int _hard_container_class_number)
{
	this->_parser->set_filename(this->vec_of_hard_container_class[_hard_container_class_number].get_path());

	cout << endl << "Now in work: " << this->vec_of_hard_container_class[_hard_container_class_number].get_path() << endl;

	char utf9[512];

	list<string> list_of_lemmatized_words;
	auto parsed_text = this->_parser->parse();


	for (string obj : parsed_text) {
		auto is_lemmas_if_good = sol_GetLemmaA(hEngine, obj.c_str(), utf9, sizeof(utf9));
		list_of_lemmatized_words.push_back(utf9);
	}

	this->_analyzer->set_list_of_all_parsed_text(list_of_lemmatized_words);
	this->_analyzer->set_container_class(&(this->vec_of_hard_container_class[_hard_container_class_number]));
	this->_analyzer->set_k(GAP);
	this->_analyzer->shape_vec_of_tokens();
	this->_analyzer->shape_vec_tokens_of_text();
	this->_analyzer->give_space(this->max_cont_size);
	this->_analyzer->analyze_vec_of_tokens();
	this->_analyzer->update_dictionary();
	this->_analyzer->clear();
	list_of_lemmatized_words.clear();
}

void Singleton::calculate_max_cont_size()
{
	for (auto obj : this->vec_of_hard_container_class) {
		this->_parser->set_filename(obj.get_path());
		char utf9[512];

		list<string> list_of_lemmatized_words;
		auto parsed_text = this->_parser->parse();


		for (string obj : parsed_text) {
			auto is_lemmas_if_good = sol_GetLemmaA(hEngine, obj.c_str(), utf9, sizeof(utf9));
			list_of_lemmatized_words.push_back(utf9);
		}

		this->_analyzer->set_list_of_all_parsed_text(list_of_lemmatized_words);
		this->_analyzer->set_container_class(&obj);
		this->_analyzer->set_k(GAP);
		this->_analyzer->shape_vec_of_tokens();
		this->_analyzer->shape_vec_tokens_of_text();
		this->_analyzer->update_dictionary();
		this->_analyzer->clear();
		list_of_lemmatized_words.clear();

		if (obj.counter_of_tokenizer > this->max_cont_size)
			this->max_cont_size = obj.counter_of_tokenizer;
	}

	cout << endl << "Max cont. size: " << this->max_cont_size << endl;
}
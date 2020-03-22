#include "Singleton.h"

Singleton& Singleton::initialization()
{
	static Singleton _singleton;
	return _singleton;
}

void Singleton::push_container(container_class_interface* _container_class)
{
	this->vec_of_container_class_interface.push_back(_container_class);
}

vector<container_class_interface*> Singleton::get_vec_of_container_class_interface() const
{
	return this->vec_of_container_class_interface;
}

int Singleton::get_length_of_all_hard_container_class() const
{
	int counter_of_all_elems = 0;
	for (auto obj_of_cont_class : this->vec_of_container_class_interface)
		for (auto first_index = 0; first_index < obj_of_cont_class->get_counter_of_tokenizer(); ++first_index)
			for (auto second_index = 0; second_index < obj_of_cont_class->get_counter_of_tokenizer(); ++second_index)
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
	this->sample_mean_all = new hard_container_class(0, GAP, hard_container_class_, "NULLLINK");
	this->sample_mean_all->give_space(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP);
	
	for (auto obj_of_cont_class : this->vec_of_container_class_interface) {
		this->prepare_data_in_container_class(obj_of_cont_class);
		cout << endl << "Size of this text: " << obj_of_cont_class->get_counter_of_tokenizer();
		if (obj_of_cont_class->get_counter_of_tokenizer() > this->max_cont_size) {
			cout << endl << "Now MAXSIZE: " << this->max_cont_size;
			this->max_cont_size = obj_of_cont_class->get_counter_of_tokenizer();
			this->sinchronize_terms(this->sample_mean_all);
		}
		*sample_mean_all += *obj_of_cont_class;
		obj_of_cont_class->clear();
	}

	*sample_mean_all = *sample_mean_all / this->vec_of_container_class_interface.size();
	this->sample_mean_all = sample_mean_all;
}

void Singleton::calculate_mat_ozidanie()
{
	this->mat_ozidanie = new hard_container_class(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP, hard_container_class_, "NULLLINK");
	this->mat_ozidanie->give_space(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP);

	for (auto obj_of_cont_class : this->vec_of_container_class_interface) {
		this->prepare_data_in_container_class(obj_of_cont_class);
		*(this->mat_ozidanie) += *obj_of_cont_class;
		obj_of_cont_class->clear();
	}

	this->mat_ozidanie = &(*(this->mat_ozidanie) / (this->divider(this->vec_of_container_class_interface.size()) * (2 + 2 * GAP)));
}

void Singleton::calculate_mat_disperse()
{
	this->mat_disperse = new hard_container_class(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP, hard_container_class_, "NULLLINK");
	this->mat_disperse->give_space(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP);

	for (auto obj_of_cont_class : this->vec_of_container_class_interface) {
		this->prepare_data_in_container_class(obj_of_cont_class);
		*this->mat_disperse += (*obj_of_cont_class).pow_all(2);
		obj_of_cont_class->clear();
	}

	this->mat_disperse = &(*(this->mat_disperse) / (this->divider(this->vec_of_container_class_interface.size()) * (2 + 2 * GAP)));

	this->mat_disperse = &(*(this->mat_disperse) - (this->mat_ozidanie->pow_all(2)));
}

void Singleton::calculate_sredne_kv_otklonenie()
{
	this->sredne_kv_otklonenie = new hard_container_class(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP, hard_container_class_, "NULLLINK");
	this->sredne_kv_otklonenie->give_space(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP);

	this->sredne_kv_otklonenie = &(this->mat_disperse->pow_all(2));
}

void Singleton::calculate_sredne_kv_otklonenie_fixed()
{
	this->sredne_kv_otklonenie_fixed = new hard_container_class(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP, hard_container_class_, "NULLLINK");
	this->sredne_kv_otklonenie_fixed->give_space(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP);

	this->sredne_kv_otklonenie_fixed = &(*(this->mat_disperse) * (this->vec_of_container_class_interface.size() / (this->vec_of_container_class_interface.size() - 1)));
	//////ÎÏÀÑÍÎÅ ÄÅËÅÍÈÅ ÍÀ 0!!!!! ÒÅÊÑÒ ÍÅ ÄÎËÆÅÍ ÁÛÒÜ ÎÄÈÍ!!!

	this->sredne_kv_otklonenie_fixed = &this->sredne_kv_otklonenie_fixed->sqrt_all();
}

void Singleton::calculate_asymmetry_coefficient()						//////todo//////
{
	this->asymmetry_coefficient = new hard_container_class(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP, hard_container_class_, "NULLLINK");
	this->asymmetry_coefficient->give_space(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP);

	for (auto obj_of_cont_class : this->vec_of_container_class_interface) {
		this->prepare_data_in_container_class(obj_of_cont_class);
		*this->asymmetry_coefficient += (*obj_of_cont_class - *this->get_sample_mean_all()).pow_all(3);
		obj_of_cont_class->clear();
	}

	this->asymmetry_coefficient = &((*this->asymmetry_coefficient / this->vec_of_container_class_interface.size()) / this->get_sredne_kv_otklonenie_fixed()->pow_all(3));
	/////zdes' ispolzovano ispravlennoe otklonenie!!!!!
}

void Singleton::calculate_excess_ratio()								//////todo//////
{
	this->excess_ratio = new hard_container_class(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP, hard_container_class_, "NULLLINK");
	this->excess_ratio->give_space(vec_of_container_class_interface.back()->get_counter_of_tokenizer(), GAP);

	for (auto obj_of_cont_class : this->vec_of_container_class_interface)
		*this->excess_ratio += (*obj_of_cont_class - *this->get_sample_mean_all()).pow_all(4);

	this->excess_ratio = &((*this->excess_ratio / this->vec_of_container_class_interface.size()) / this->get_sredne_kv_otklonenie_fixed()->pow_all(4) - 3);
	/////ÍÓÆÍÎ ÍÀÏÈÑÀÒÜ ÎÏÅÐÀÒÎÐ ÄÅËÅÍÈß ÊÎÍÒÅÉÍÅÐÎÃÎ ÊËÀÑÑÀ ÍÀ ÊÎÍÒÅÉÍÅÐÍÛÉ ÊËÀÑÑ, À ÇÀÒÅÌ ÐÀÑÊÎÌÌÅÍÒÈÒÜ ÑÒÐÎÊÓ ÂÛØÅ
	/////zdes' ispolzovano ispravlennoe otklonenie!!!!!
}

container_class_interface* Singleton::get_sredne_kv_otklonenie() const
{
	return this->sredne_kv_otklonenie;
}

container_class_interface* Singleton::get_sredne_kv_otklonenie_fixed() const
{
	return this->sredne_kv_otklonenie_fixed;
}

container_class_interface* Singleton::get_mat_ozidanie() const
{
	return this->mat_ozidanie;
}

container_class_interface* Singleton::get_mat_disperse() const
{
	return this->mat_disperse;
}

container_class_interface* Singleton::get_asymmetry_coefficient() const
{
	return this->asymmetry_coefficient;
}

container_class_interface* Singleton::get_excess_ratio() const
{
	return this->excess_ratio;
}

container_class_interface* Singleton::get_sample_mean_all() const
{
	return this->sample_mean_all;
}

bool Singleton::remove_hard_container_class(container_class_interface* _hard_container_class)
{
	vector<container_class_interface*>::iterator tmp = find(this->vec_of_container_class_interface.begin(), this->vec_of_container_class_interface.end(), _hard_container_class);
	if (tmp == this->vec_of_container_class_interface.end())
		return false;
	this->vec_of_container_class_interface.erase(tmp);
	return true;
}

void Singleton::calculate_params_for_charts()	//TODO
{
	this->sum = &(*this->calculate_parametr_to_one_term(this->mat_ozidanie) + *this->calculate_parametr_to_one_term(this->sredne_kv_otklonenie_fixed));
	this->razn = &(*this->calculate_parametr_to_one_term(this->mat_ozidanie) - *this->calculate_parametr_to_one_term(this->sredne_kv_otklonenie_fixed));
	this->shhh = this->calculate_parametr_to_one_term(this->mat_ozidanie);

	container_class_interface* chart1 = new hard_container_class(this->vec_of_container_class_interface[0]->get_counter_of_tokenizer(), vec_of_container_class_interface[0]->get_k(), hard_container_class_, "NULLLINK");
	auto keks = this->vec_of_container_class_interface[this->vec_of_container_class_interface.size() - 1]->get_counter_of_tokenizer();
	for (auto i : this->vec_of_container_class_interface)
	{
		for (auto q = 0; q < keks; ++q)
			for (auto j = 0; j < keks; ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					(*chart1)[q][q][p] = (*chart1)[q][q][p] + (*i)[q][j][p];
	}

	*chart1 = *chart1 / (vec_of_container_class_interface.size());
	this->chart = chart1;
}

void Singleton::find_fluctuations()	//TODO
{
	analyzer helper;
	helper.set_map_of_tokens("dictionary.txt");
	ofstream ff("fluctuation.txt");
	for (int i = 1; i < this->chart->get_counter_of_tokenizer(); i++)
		for (int l = -GAP - 1; l <= GAP; ++l)
			if (((*chart)[i][i][l] > (*sum)[i][i][l]) || ((*chart)[i][i][l] < (*razn)[i][i][l])) {
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
		this->mat_ozidanie->clear();
		break;
	case mat_disperse_:
		this->mat_disperse->clear();
		break;
	case mat_otkl_:
		this->sredne_kv_otklonenie->clear();
		break;
	case mat_otkl_fixed_:
		this->sredne_kv_otklonenie_fixed->clear();
		break;
	case excess_ratio_:
		this->excess_ratio->clear();
		break;
	case asymmetry_coefficient_:
		this->asymmetry_coefficient->clear();
		break;
	case sample_mean_all_:
		this->sample_mean_all->clear();
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
	auto keks = this->vec_of_container_class_interface[this->vec_of_container_class_interface.size() - 1]->get_counter_of_tokenizer();

	ofstream to_chart("chart.txt");

		for (int i = 1; i < chart->get_counter_of_tokenizer(); ++i)
			{
					to_chart << endl << endl << "term " << i << endl;
					for (int l = -GAP - 1; l <= GAP; ++l) 
						if(l==-GAP-1)
							to_chart << "really: " << (*chart)[i][i][l] << " ";
						else 
							to_chart << (*chart)[i][i][l] << " ";

					to_chart << endl;

					for (int l = -GAP - 1; l <= GAP; ++l)
						if (l == -GAP - 1)
							to_chart << "mat_ozhidanie: " << (*shhh)[i][i][l] << " ";
						else 
							to_chart << (*shhh)[i][i][l] << " ";

					to_chart << endl;

					for (int l = -GAP - 1; l <= GAP; ++l)
						if (l == -GAP - 1)
							to_chart << "mat_ozhidanie+otkl: " << (*sum)[i][i][l] << " ";
						else 
							to_chart << (*sum)[i][i][l] << " ";

					to_chart << endl;

					for (int l = -GAP - 1; l <= GAP; ++l)
						if (l == -GAP - 1)
							to_chart << "mat_ozhidanie-otkl: " << (*razn)[i][i][l] << " ";
						else 
							to_chart << (*razn)[i][i][l] << " ";	
		}
		to_chart.close();
}

void Singleton::sinchronize_terms()
{
	int max_size = this->vec_of_container_class_interface.back()->get_counter_of_tokenizer();

	for (auto obj : this->vec_of_container_class_interface)
		obj->set_counter_of_tokenizer(max_size);

	/*	vector<container_class_interface*> new_vec;
	new_vec.reserve(this->vec_of_container_class_interface.size());
	for (auto obj : this->vec_of_container_class_interface) {
		container_class_interface* new_cont_class = new hard_container_class(max_size, obj->get_k(), hard_container_class_, "NULLLINK");
		for (auto q = 0; q < obj->get_counter_of_tokenizer(); ++q)
			for (auto j = 0; j < obj->get_counter_of_tokenizer(); ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					(*new_cont_class)[q][j][p] = (*obj)[q][j][p];

		new_vec.push_back(new_cont_class);
	}

	this->vec_of_container_class_interface = new_vec;*/
}

void Singleton::sinchronize_terms(container_class_interface* _container_class)
{
	container_class_interface* new_cont_class = new hard_container_class(this->max_cont_size, _container_class->get_k(), hard_container_class_, "NULLLINK");
	new_cont_class->give_space(this->max_cont_size, _container_class->get_k());
	for (auto q = 0; q < _container_class->get_counter_of_tokenizer(); ++q)
		for (auto j = 0; j < _container_class->get_counter_of_tokenizer(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				(*new_cont_class)[q][j][p] = (*_container_class)[q][j][p];

}

container_class_interface* Singleton::calculate_parametr_to_one_term(container_class_interface* _parametr)
{
	for (auto q = 0; q < _parametr->get_counter_of_tokenizer(); ++q)
		for (auto j = 0; j < _parametr->get_counter_of_tokenizer(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				_parametr[q][q][p] += _parametr[q][j][p];
	return _parametr;
}

void Singleton::prepare_data_with_link_for_text(fs::path filename)
{
	this->push_container(new hard_container_class(GAP, hard_container_class_, filename));
}

void Singleton::prepare_data_in_container_class(container_class_interface* _container_class_interface)
{
	this->_parser->set_filename(_container_class_interface->get_path());

	cout << endl << "Now in work: " << _container_class_interface->get_path() << endl;

	char utf9[512];

	list<string> list_of_lemmatized_words;
	auto parsed_text = this->_parser->parse();


	for (string obj : parsed_text) {
		auto is_lemmas_if_good = sol_GetLemmaA(hEngine, obj.c_str(), utf9, sizeof(utf9));
		list_of_lemmatized_words.push_back(utf9);
	}

	this->_analyzer->set_list_of_all_parsed_text(&list_of_lemmatized_words);
	this->_analyzer->set_container_class(_container_class_interface);
	this->_analyzer->set_k(GAP);
	this->_analyzer->shape_vec_of_tokens();
	this->_analyzer->shape_vec_tokens_of_text();
	this->_analyzer->give_space();
	this->_analyzer->analyze_vec_of_tokens();
	this->_analyzer->update_dictionary();
	this->_analyzer->clear();
	list_of_lemmatized_words.clear();
}
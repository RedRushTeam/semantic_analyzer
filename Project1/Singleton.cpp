#include "Singleton.h"

Singleton& Singleton::initialization()
{
	static Singleton _singleton;
	return _singleton;
}

void Singleton::push_container(container_class _container_class)
{
	this->list_of_container_class.push_back(_container_class);
}

list<container_class> Singleton::get_list_of_container_class() const
{
	return this->list_of_container_class;
}

int Singleton::get_length_of_all_container_class() const
{
	int counter_of_all_elems = 0;
	for (auto obj_of_cont_class : this->list_of_container_class)
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
	container_class sample_mean_all;
	sample_mean_all.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));

	for (auto obj_of_cont_class : this->list_of_container_class)
		sample_mean_all += obj_of_cont_class;

	sample_mean_all = sample_mean_all / this->list_of_container_class.size();
	this->sample_mean_all = sample_mean_all;
}

void Singleton::calculate_mat_ozidanie()
{
	for (auto obj_of_cont_class : this->list_of_container_class)
		this->mat_ozidanie += obj_of_cont_class;

	this->mat_ozidanie = this->mat_ozidanie / (this->divider(this->list_of_container_class.size()) * (2 + 2 * GAP));
}

void Singleton::calculate_mat_disperse()
{
	for (auto obj_of_cont_class : this->list_of_container_class)
		this->mat_disperse += obj_of_cont_class.pow_all(2);

	this->mat_disperse = this->mat_disperse / (this->divider(this->list_of_container_class.size()) * (2 + 2 * GAP));

	this->mat_disperse = this->mat_disperse - this->mat_ozidanie.pow_all(2);
}

void Singleton::calculate_sredne_kv_otklonenie()
{
	this->sredne_kv_otklonenie = this->mat_disperse.pow_all(2);
}

void Singleton::calculate_sredne_kv_otklonenie_fixed()
{
	this->sredne_kv_otklonenie_fixed = this->mat_disperse * (this->list_of_container_class.size() / (this->list_of_container_class.size() - 1));
	//////ÎÏÀÑÍÎÅ ÄÅËÅÍÈÅ ÍÀ 0!!!!! ÒÅÊÑÒ ÍÅ ÄÎËÆÅÍ ÁÛÒÜ ÎÄÈÍ!!!

	this->sredne_kv_otklonenie_fixed = this->sredne_kv_otklonenie_fixed.sqrt_all();
}

void Singleton::calculate_asymmetry_coefficient()						//////todo//////
{
	for (auto obj_of_cont_class : this->list_of_container_class)
		this->asymmetry_coefficient += (obj_of_cont_class - this->get_sample_mean_all()).pow_all(3);


	this->asymmetry_coefficient = (this->asymmetry_coefficient / this->list_of_container_class.size()) / this->get_sredne_kv_otklonenie_fixed().pow_all(3);
	/////zdes' ispolzovano ispravlennoe otklonenie!!!!!
}

void Singleton::calculate_excess_ratio()								//////todo//////
{
	for (auto obj_of_cont_class : this->list_of_container_class)
		this->excess_ratio += (obj_of_cont_class - this->get_sample_mean_all()).pow_all(4);

	this->excess_ratio = (this->excess_ratio / this->list_of_container_class.size()) / this->get_sredne_kv_otklonenie_fixed().pow_all(4) - 3;
	/////ÍÓÆÍÎ ÍÀÏÈÑÀÒÜ ÎÏÅÐÀÒÎÐ ÄÅËÅÍÈß ÊÎÍÒÅÉÍÅÐÎÃÎ ÊËÀÑÑÀ ÍÀ ÊÎÍÒÅÉÍÅÐÍÛÉ ÊËÀÑÑ, À ÇÀÒÅÌ ÐÀÑÊÎÌÌÅÍÒÈÒÜ ÑÒÐÎÊÓ ÂÛØÅ
	/////zdes' ispolzovano ispravlennoe otklonenie!!!!!
}

container_class Singleton::get_sredne_kv_otklonenie() const
{
	return this->sredne_kv_otklonenie;
}

container_class Singleton::get_sredne_kv_otklonenie_fixed() const
{
	return this->sredne_kv_otklonenie_fixed;
}

container_class Singleton::get_mat_ozidanie() const
{
	return this->mat_ozidanie;
}

container_class Singleton::get_mat_disperse() const
{
	return this->mat_disperse;
}

container_class Singleton::get_asymmetry_coefficient() const
{
	return this->asymmetry_coefficient;
}

container_class Singleton::get_excess_ratio() const
{
	return this->excess_ratio;
}

container_class Singleton::get_sample_mean_all() const
{
	return this->sample_mean_all;
}

bool Singleton::remove_container_class(container_class _container_class)
{
	list<container_class>::iterator tmp = find(this->list_of_container_class.begin(), this->list_of_container_class.end(), _container_class);
	if (tmp == this->list_of_container_class.end())
		return false;
	this->list_of_container_class.erase(tmp);
	return true;
}

void Singleton::calculate_params_for_charts()
{
	this->sum = this->calculate_parametr_to_one_term(this->mat_ozidanie) + this->calculate_parametr_to_one_term(this->sredne_kv_otklonenie_fixed);
	this->razn = this->calculate_parametr_to_one_term(this->mat_ozidanie) - this->calculate_parametr_to_one_term(this->sredne_kv_otklonenie_fixed);
	this->shhh = this->calculate_parametr_to_one_term(this->mat_ozidanie);

	container_class chart1;
	auto keks = list_of_container_class.front().get_vector_of_length().size();
	chart1.give_space(list_of_container_class.front().get_counter_of_tokenizer(), list_of_container_class.front().get_k());
	for (auto i : this->list_of_container_class)
	{
		for (auto q = 0; q < keks; ++q)
			for (auto j = 0; j < keks; ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					chart1[q][q][p] += i[q][j][p];
	}
	chart1 = chart1 / (list_of_container_class.size());
	this->chart = chart1;
}

void Singleton::find_fluctuations()
{
	analyzer helper;
	helper.set_map_of_tokens("dictionary.txt");
	ofstream ff("fluctuation.txt");
	for (int i = 1; i < chart.get_counter_of_tokenizer(); i++)
	{
		for (int l = -GAP - 1; l <= GAP; ++l)
			if ((chart[i][i][l] > sum[i][i][l]) || (chart[i][i][l] < razn[i][i][l]))
				for (auto q : helper.get_map_of_tokens())
					if (q.second == i) {
						ff << q.first << endl;
						i++;
					}

	}
}

void Singleton::out_for_chart()
{
	/*container_class sum;
	container_class razn;
	container_class shhh;*/

	thread tr([&]() {
		/*sum = this->calculate_parametr_to_one_term(this->mat_ozidanie) + this->calculate_parametr_to_one_term(this->sredne_kv_otklonenie_fixed);
		razn = this->calculate_parametr_to_one_term(this->mat_ozidanie) - this->calculate_parametr_to_one_term(this->sredne_kv_otklonenie_fixed);
		shhh = this->calculate_parametr_to_one_term(this->mat_ozidanie);*/
		this->calculate_params_for_charts();
		});

	//container_class chart; 
	auto keks = list_of_container_class.front().get_vector_of_length().size();
	/*chart.give_space(list_of_container_class.front().get_counter_of_tokenizer(), list_of_container_class.front().get_k());
	for (auto i : this->list_of_container_class)
	{
		for (auto q = 0; q < keks; ++q)
			for (auto j = 0; j < keks; ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					chart[q][q][p] += i[q][j][p];
	}
	chart = chart / (list_of_container_class.size());*/

	ofstream to_chart("chart.txt");

	tr.join();

		for (int i = 1; i < chart.get_counter_of_tokenizer(); ++i)
			{
					to_chart << endl << endl << "term " << i << endl;
					for (int l = -GAP - 1; l <= GAP; ++l) 
						if(l==-GAP-1)
							to_chart << "really: " << chart[i][i][l] << " ";
						else 
							to_chart << chart[i][i][l] << " ";

					to_chart << endl;

					for (int l = -GAP - 1; l <= GAP; ++l)
						if (l == -GAP - 1)
							to_chart << "mat_ozhidanie: " << shhh[i][i][l] << " ";
						else 
							to_chart << shhh[i][i][l] << " ";

					to_chart << endl;

					for (int l = -GAP - 1; l <= GAP; ++l)
						if (l == -GAP - 1)
							to_chart << "mat_ozhidanie+otkl: " << sum[i][i][l] << " ";
						else 
							to_chart << sum[i][i][l] << " ";

					to_chart << endl;

					for (int l = -GAP - 1; l <= GAP; ++l)
						if (l == -GAP - 1)
							to_chart << "mat_ozhidanie-otkl: " << razn[i][i][l] << " ";
						else 
							to_chart << razn[i][i][l] << " ";	
		}
		to_chart.close();
}

void Singleton::sinchronize_terms()
{
	int max_size = this->list_of_container_class.back().get_length();
	list<container_class> new_list;
	for (auto obj : this->list_of_container_class) {
		container_class new_cont_class(max_size, obj.get_k());
		for (auto q = 0; q < obj.get_counter_of_tokenizer(); ++q)
			for (auto j = 0; j < obj.get_counter_of_tokenizer(); ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					new_cont_class[q][j][p] = obj[q][j][p];

		new_list.push_back(new_cont_class);
	}
	this->list_of_container_class = new_list;
}

void Singleton::give_space()
{
	this->excess_ratio.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));
	this->asymmetry_coefficient.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));
	this->sredne_kv_otklonenie_fixed.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));
	this->sredne_kv_otklonenie.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));
	this->mat_disperse.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));
	this->mat_ozidanie.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));
}

container_class Singleton::calculate_parametr_to_one_term(container_class _parametr)
{
	for (auto q = 0; q < _parametr.get_counter_of_tokenizer(); ++q)
		for (auto j = 0; j < _parametr.get_counter_of_tokenizer(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				_parametr[q][q][p] += _parametr[q][j][p];
	return _parametr;
}


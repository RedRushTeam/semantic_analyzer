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

container_class Singleton::calculate_sample_mean()
{
	container_class sample_mean_all;
	sample_mean_all.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));

	for (auto obj_of_cont_class : this->list_of_container_class)
		sample_mean_all += obj_of_cont_class;

	sample_mean_all = sample_mean_all / this->list_of_container_class.size();
	return sample_mean_all;
}

void Singleton::calculate_mat_ozidanie()
{
	container_class mat_ozidanie_all;
	mat_ozidanie_all.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));
	for (auto obj_of_cont_class : this->list_of_container_class)
		mat_ozidanie_all += obj_of_cont_class;


	this->mat_ozidanie = mat_ozidanie_all / (this->divider(this->list_of_container_class.size()) * (2 + 2 * GAP));		////??????????
}

void Singleton::calculate_mat_disperse()												//////todo//////
{
	container_class mat_disperse_all;
	mat_disperse_all.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));
	for (auto obj_of_cont_class : this->list_of_container_class)
		mat_disperse_all += obj_of_cont_class.pow_all(2);

	container_class mat_ozidanie_square;
	mat_ozidanie_square.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));

	mat_ozidanie_square = mat_disperse_all / (this->divider(this->list_of_container_class.size()) * (2 + 2 * GAP));		///////????????????

	this->mat_disperse = mat_ozidanie_square - this->mat_ozidanie.pow_all(2);
}

void Singleton::calculate_sredne_kv_otklonenie()
{
	this->sredne_kv_otklonenie = this->mat_disperse.pow_all(2);
}

void Singleton::calculate_sredne_kv_otklonenie_fixed()
{
	container_class dispersion_fixed_2;
	dispersion_fixed_2.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));

	//dispersion_fixed_2 = this->mat_disperse * (this->list_of_container_class.size() / (this->list_of_container_class.size() - 1)); 
	//////ÎÏÀÑÍÎÅ ÄÅËÅÍÈÅ ÍÀ 0!!!!! ÒÅÊÑÒ ÍÅ ÄÎËÆÅÍ ÁÛÒÜ ÎÄÈÍ!!!

	this->sredne_kv_otklonenie_fixed = dispersion_fixed_2.sqrt_all();
}

void Singleton::calculate_asymmetry_coefficient()						//////todo//////
{
	container_class summ_of_m3;
	summ_of_m3.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));
	for (auto obj_of_cont_class : this->list_of_container_class)
			summ_of_m3 +=(obj_of_cont_class - this->calculate_sample_mean()).pow_all(3);


	//this->asymmetry_coefficient = (summ_of_m3 / this->list_of_container_class.size()) / this->get_sredne_kv_otklonenie_fixed().pow_all(3);
	/////ÍÓÆÍÎ ÍÀÏÈÑÀÒÜ ÎÏÅÐÀÒÎÐ ÄÅËÅÍÈß ÊÎÍÒÅÉÍÅÐÎÃÎ ÊËÀÑÑÀ ÍÀ ÊÎÍÒÅÉÍÅÐÍÛÉ ÊËÀÑÑ, À ÇÀÒÅÌ ÐÀÑÊÎÌÌÅÍÒÈÒÜ ÑÒÐÎÊÓ ÂÛØÅ
	/////zdes' ispolzovano ispravlennoe otklonenie!!!!!
}

void Singleton::calculate_excess_ratio()								//////todo//////
{
	container_class summ_of_m4;
	summ_of_m4.give_space(this->list_of_container_class.begin()->get_counter_of_tokenizer(), (GAP * 2 + 2));
	for (auto obj_of_cont_class : this->list_of_container_class)
		summ_of_m4 += summ_of_m4 + (obj_of_cont_class - this->calculate_sample_mean()).pow_all(4);

	//this->excess_ratio = (summ_of_m4 / this->list_of_container_class.size()) / this->get_sredne_kv_otklonenie_fixed().pow_all(4) - 3;
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

/*bool Singleton::remove_container_class(container_class _container_class)
{
	//auto tmp = find(this->list_of_container_class.begin(), this->list_of_container_class.end(), _container_class);
	//if (tmp == this->list_of_container_class.end())
		//return false;
	//this->list_of_container_class.erase(tmp);
	return true;
}*/

void Singleton::out_for_chart()
{
	container_class chart;
	chart.give_space(list_of_container_class.front.get_counter_of_tokenizer(), list_of_container_class.front.get_k());
	for (auto i : this->list_of_container_class)
	{
		for (auto q = 0; q < i.get_vector_of_length.size(); ++q)
			for (auto j = 0; j < i.get_vector_of_length.size(); ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					chart[q][j][p] += i[q][j][p];
	}
	chart = chart / (this->list_of_container_class.size());
	ofstream to_chart("chart");
	
		for (int i = 0; i < chart.get_counter_of_tokenizer(); ++i)
			for (int j = 0; j < chart.get_counter_of_tokenizer(); ++j)
			{
				if (i != 0 && j != 0 && i <= j) {
					to_chart << endl << endl << i << " " << j << endl;
					for (int l = -GAP - 1; l <= GAP; ++l)
						to_chart << chart[i][j][l] << " ";
				}
			}
}


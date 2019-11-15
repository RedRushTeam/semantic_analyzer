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

my_double Singleton::calculate_sample_mean()
{
	my_double summ_of_all_collocations = 0;
	for (auto obj_of_cont_class : this->list_of_container_class)
		for (auto first_index = 0; first_index < obj_of_cont_class.get_counter_of_tokenizer(); ++first_index)
			for (auto second_index = 0; second_index < obj_of_cont_class.get_counter_of_tokenizer(); ++second_index)
				for (auto third_index = -GAP - 1; third_index <= GAP; ++third_index)
					if (first_index <= second_index)
						summ_of_all_collocations = summ_of_all_collocations + obj_of_cont_class[first_index][second_index][third_index];

	my_double sample_mean = summ_of_all_collocations / this->get_length_of_all_container_class();
	return sample_mean;
}

void Singleton::calculate_mat_ozidanie()
{
	my_double summ_of_all_collocations = 0;
	int counter_of_tokenizer;
	for (auto obj_of_cont_class : this->list_of_container_class)
		for (auto first_index = 0; first_index < obj_of_cont_class.get_counter_of_tokenizer(); ++first_index)
			for (auto second_index = 0; second_index < obj_of_cont_class.get_counter_of_tokenizer(); ++second_index)
				for (auto third_index = -GAP - 1; third_index <= GAP; ++third_index)
					if (first_index <= second_index) {
						summ_of_all_collocations = summ_of_all_collocations + obj_of_cont_class[first_index][second_index][third_index];
						counter_of_tokenizer = obj_of_cont_class.get_counter_of_tokenizer();
					}

	this->mat_ozidanie = summ_of_all_collocations / (this->divider(counter_of_tokenizer) * (2 + 2 * GAP));
}

void Singleton::calculate_mat_disperse()
{
	my_double summ_of_all_collocations_2 = 0;
	int counter_of_tokenizer;
	for (auto obj_of_cont_class : this->list_of_container_class)
		for (auto first_index = 0; first_index < obj_of_cont_class.get_counter_of_tokenizer(); ++first_index)
			for (auto second_index = 0; second_index < obj_of_cont_class.get_counter_of_tokenizer(); ++second_index)
				for (auto third_index = -GAP - 1; third_index <= GAP; ++third_index)
					if (first_index <= second_index){
						summ_of_all_collocations_2 = summ_of_all_collocations_2 + pow(obj_of_cont_class[first_index][second_index][third_index], 2);
						counter_of_tokenizer = obj_of_cont_class.get_counter_of_tokenizer();
					}

	my_double mat_ozidanie_square = summ_of_all_collocations_2 / (this->divider(counter_of_tokenizer) * (2 + 2 * GAP));

	this->mat_disperse = mat_ozidanie_square - pow(this->mat_ozidanie, 2);
}

void Singleton::calculate_sredne_kv_otklonenie()
{
	this->sredne_kv_otklonenie = pow(this->mat_disperse, 2);
}

void Singleton::calculate_sredne_kv_otklonenie_fixed()
{
	int counter_of_all_elems = this->get_length_of_all_container_class();

	my_double dispersion_fixed_2 = (counter_of_all_elems / (counter_of_all_elems - 1)) * this->mat_disperse;

	this->sredne_kv_otklonenie_fixed = sqrt(dispersion_fixed_2);
}

void Singleton::calculate_asymmetry_coefficient()
{
	my_double summ_of_m3 = 0;
	for (auto obj_of_cont_class : this->list_of_container_class)
		for (auto first_index = 0; first_index < obj_of_cont_class.get_counter_of_tokenizer(); ++first_index)
			for (auto second_index = 0; second_index < obj_of_cont_class.get_counter_of_tokenizer(); ++second_index)
				for (auto third_index = -GAP - 1; third_index <= GAP; ++third_index)
					if (first_index <= second_index) {
						summ_of_m3 = summ_of_m3 + pow((obj_of_cont_class[first_index][second_index][third_index] - this->calculate_sample_mean()), 3);
					}

	this->asymmetry_coefficient= (summ_of_m3 / this->get_length_of_all_container_class())/pow(this->get_sredne_kv_otklonenie_fixed(), 3);				/////zdes' ispolzovano ispravlennoe otklonenie!!!!!
}

void Singleton::calculate_excess_ratio()
{
	my_double summ_of_m4 = 0;
	for (auto obj_of_cont_class : this->list_of_container_class)
		for (auto first_index = 0; first_index < obj_of_cont_class.get_counter_of_tokenizer(); ++first_index)
			for (auto second_index = 0; second_index < obj_of_cont_class.get_counter_of_tokenizer(); ++second_index)
				for (auto third_index = -GAP - 1; third_index <= GAP; ++third_index)
					if (first_index <= second_index) {
						summ_of_m4 = summ_of_m4 + pow((obj_of_cont_class[first_index][second_index][third_index] - this->calculate_sample_mean()), 4);
					}

	this->excess_ratio = (summ_of_m4 / this->get_length_of_all_container_class()) / pow(this->get_sredne_kv_otklonenie_fixed(), 4) - 3;				/////zdes' ispolzovano ispravlennoe otklonenie!!!!!
}

void Singleton::calculate_koef_assim()
{
	int counter_of_all_elems = 0;
	for (auto obj_of_cont_class : this->list_of_container_class)
		for (auto first_index = 0; first_index < obj_of_cont_class.get_counter_of_tokenizer(); ++first_index)
			for (auto second_index = 0; second_index < obj_of_cont_class.get_counter_of_tokenizer(); ++second_index)
				for (auto third_index = -GAP - 1; third_index <= GAP; ++third_index)
					if (first_index <= second_index)
						++counter_of_all_elems;


}

my_double Singleton::get_sredne_kv_otklonenie() const
{
	return this->sredne_kv_otklonenie;
}

my_double Singleton::get_sredne_kv_otklonenie_fixed() const
{
	return this->sredne_kv_otklonenie_fixed;
}

my_double Singleton::get_mat_ozidanie() const
{
	return this->mat_ozidanie;
}

my_double Singleton::get_mat_disperse() const
{
	return this->mat_disperse;
}

my_double Singleton::get_asymmetry_coefficient() const
{
	return this->asymmetry_coefficient;
}

my_double Singleton::get_excess_ratio() const
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
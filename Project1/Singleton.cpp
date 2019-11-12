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

my_double Singleton::divider(int size) {
	int starter = 1;
	int finisher = size;
	auto sum = (starter + finisher) * (finisher - starter + 1) / 2;
	return sum;
}

void Singleton::calculate_mat_ozidanie()
{
	my_double summ_of_all_collocations = 0;
	int counter_of_tokenizer;
	for (auto obj_of_cont_class : this->list_of_container_class)
		for (auto first_index = 0; first_index < obj_of_cont_class.get_counter_of_tokenizer(); ++first_index)
			for (auto second_index = 0; second_index < obj_of_cont_class.get_counter_of_tokenizer(); ++second_index)
				for (auto third_index = 0; third_index < obj_of_cont_class.get_counter_of_tokenizer(); ++third_index)
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
				for (auto third_index = 0; third_index < obj_of_cont_class.get_counter_of_tokenizer(); ++third_index)
					if (first_index <= second_index){
						summ_of_all_collocations_2 = summ_of_all_collocations_2 + pow(obj_of_cont_class[first_index][second_index][third_index], 2);
						counter_of_tokenizer = obj_of_cont_class.get_counter_of_tokenizer();
					}

	my_double mat_ozidanie_square = summ_of_all_collocations_2 / (this->divider(counter_of_tokenizer) * (2 + 2 * GAP));

	this->mat_disperse = mat_ozidanie_square - pow(this->mat_ozidanie, 2);
}

my_double Singleton::get_mat_ozidanie() const
{
	return this->mat_ozidanie;
}

/*bool Singleton::remove_container_class(container_class _container_class)
{
	//auto tmp = find(this->list_of_container_class.begin(), this->list_of_container_class.end(), _container_class);
	//if (tmp == this->list_of_container_class.end())
		//return false;
	//this->list_of_container_class.erase(tmp);
	return true;
}*/
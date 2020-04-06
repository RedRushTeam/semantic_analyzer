#include "class_of_first_bracket.h"

void class_of_first_bracket::give_space(int counter_of_tokenizer, int k)
{
	this->counter_of_tokenizer = counter_of_tokenizer;

	this->vector_of_length = new class_of_collocation[counter_of_tokenizer]();
}

void class_of_first_bracket::clear()
{
	for (int i = 0; this->counter_of_tokenizer > i; ++i)
		this->vector_of_length[i].clear();

	delete[] vector_of_length;
	this->vector_of_length = NULL;
}

/*void class_of_first_bracket::push_back(class_of_collocation coc)
{
	this->vector_of_length.push_back(coc);
}*/

class_of_collocation& class_of_first_bracket::operator[](long int i)
{
	return vector_of_length[i];
}

void class_of_first_bracket::set_vector_of_lenght(class_of_collocation* massiv)
{
	for (auto i = 0; i < counter_of_tokenizer; ++i)
		vector_of_length[i] = massiv[i];
}
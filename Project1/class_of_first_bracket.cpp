#include "class_of_first_bracket.h"

/*void class_of_first_bracket::resize(long int i)
{
	this->vector_of_length.resize(i); //todo
}*/

/*void class_of_first_bracket::assign(long int i, class_of_collocation _class_of_collocation)
{
	this->vector_of_length.assign(i, _class_of_collocation);
}*/

class_of_first_bracket class_of_first_bracket::pow_all(int stepen)
{
	class_of_first_bracket cl_for_return;
	//cl_for_return.resize(this->counter_of_tokenizer/*this->vector_of_length.size()*/);

	for (int i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
		cl_for_return[i] = this->vector_of_length[i].pow_all(stepen);

	return cl_for_return;
}

class_of_first_bracket class_of_first_bracket::sqrt_all()
{
	class_of_first_bracket cl_for_return;
	//cl_for_return.resize(counter_of_tokenizer/*this->vector_of_length.size()*/);

	for (int i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
		cl_for_return[i] = vector_of_length[i].sqrt_all();

	return cl_for_return;
}

/*void class_of_first_bracket::push_back(class_of_collocation coc)
{
	this->vector_of_length.push_back(coc);
}*/

class_of_collocation& class_of_first_bracket::operator[](long int i)
{
	return vector_of_length[i];
}
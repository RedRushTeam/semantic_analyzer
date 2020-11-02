#include "class_of_first_bracket_for_sparce_container_class.h"

void class_of_first_bracket_for_sparce_container_class::give_space(int counter_of_tokenizer, int k)
{
	//kostil
}

void class_of_first_bracket_for_sparce_container_class::clear()
{
	this->vector_of_length->clear();
	this->vector_of_length = NULL;
}

class_of_collocation_for_sparce_cont_class& class_of_first_bracket_for_sparce_container_class::operator[](long int i)
{
	this->vector_of_length->set_second_bracket(i);
	return *(this->vector_of_length);
}

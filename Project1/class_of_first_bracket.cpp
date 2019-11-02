#include "class_of_first_bracket.h"

void class_of_first_bracket::resize(long int i)
{
	this->vector_of_length.resize(i);
}

class_of_collocation& class_of_first_bracket::operator[](long int i)
{
	return vector_of_length[i];
}
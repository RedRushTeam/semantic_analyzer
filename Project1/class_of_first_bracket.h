#pragma once
#include "class_of_collocation.h"
class class_of_first_bracket
{
public:
	//methods
	void give_space(int counter_of_tokenizer, int k);
	void clear();

	//getter
	class_of_collocation* get_vector_of_length() { return this->vector_of_length; };
	//setter
	void set_vector_of_lenght(class_of_collocation* massiv);

	//operators
	class_of_collocation& operator[](long int i);


	int counter_of_tokenizer;
private:
	class_of_collocation* vector_of_length;
	
};

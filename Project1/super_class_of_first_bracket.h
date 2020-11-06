#pragma once
#include "super_class_of_collocation.h"

class super_class_of_first_bracket
{
public:
	//methods
	virtual void give_space(int counter_of_tokenizer, int k) = 0;
	virtual void clear() = 0;
	virtual void set_first_bracket_counter(int i);

	//operators
	virtual super_class_of_collocation& operator[](long int i) = 0;


	int counter_of_tokenizer;
};


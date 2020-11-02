#pragma once
#include "class_of_collocation_for_sparce_cont_class.h"

class class_of_first_bracket_for_sparce_container_class
{
public:
	//methods
	void give_space(int counter_of_tokenizer, int k);
	void clear();

	//operators
	class_of_collocation_for_sparce_cont_class& operator[](long int i);


	int counter_of_tokenizer;
private:
	class_of_collocation_for_sparce_cont_class* vector_of_length;
};


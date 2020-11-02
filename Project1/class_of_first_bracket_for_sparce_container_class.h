#pragma once
#include "class_of_collocation_for_sparce_cont_class.h"

class class_of_first_bracket_for_sparce_container_class
{
public:
	//constr
	class_of_first_bracket_for_sparce_container_class() {
		this->vector_of_length = new class_of_collocation_for_sparce_cont_class();
	}

	//methods
	void give_space(int counter_of_tokenizer, int k);
	void clear();
	void set_first_bracket_counter(int i);

	//operators
	class_of_collocation_for_sparce_cont_class& operator[](long int i);


	int counter_of_tokenizer;
private:
	class_of_collocation_for_sparce_cont_class* vector_of_length;
};


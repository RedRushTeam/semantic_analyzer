#pragma once
#include "class_of_collocation.h"
class class_of_first_bracket
{
public:
	//methods
	void give_space(long int i);
	//void assign(long int i, class_of_collocation _class_of_collocation);
	class_of_first_bracket pow_all(int stepen);
	class_of_first_bracket sqrt_all();
	//void push_back(class_of_collocation coc);
	

	//getter
	class_of_collocation* get_vector_of_length() { return this->vector_of_length; };

	//operators
	class_of_collocation& operator[](long int i);


	static int counter_of_tokenizer;
private:
	class_of_collocation* vector_of_length;
	
};

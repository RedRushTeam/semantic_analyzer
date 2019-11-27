#pragma once
#include "class_of_collocation.h"
class class_of_first_bracket
{
public:
	//methods
	void resize(long int i);
	class_of_first_bracket pow_all(int stepen);
	class_of_first_bracket sqrt_all();
	void push_back(class_of_collocation coc);

	//operators
	class_of_collocation& operator[](long int i);

private:
	vector<class_of_collocation> vector_of_length;
};

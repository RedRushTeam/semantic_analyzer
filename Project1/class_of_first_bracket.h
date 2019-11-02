#pragma once
#include "class_of_collocation.h"
class class_of_first_bracket
{
public:
	//methods
	void resize(long int i);

	//operators
	class_of_collocation& operator[](long int i);

private:
	vector<class_of_collocation> vector_of_length;
};

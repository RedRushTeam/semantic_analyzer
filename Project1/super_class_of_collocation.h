#pragma once
#include "parser.h"
class super_class_of_collocation
{
public:

	//methods
	virtual void give_space(int k) = 0;
	virtual void increment(int third_demention) = 0;
	virtual my_double get_count_of_concret_collocation(int third_demention) = 0;
	//my_double* get_vect_of_collocation() { return vect_of_collocation; };
	//virtual void set_vect_of_collocation(my_double* massiv, int k);
	virtual void pow_all(int stepen) = 0;
	virtual void sqrt_all() = 0;
	virtual void clear() = 0;

	//operators
	virtual my_double& operator[](long int i) = 0;
	virtual super_class_of_collocation* operator+(super_class_of_collocation* summed_class) = 0;
	virtual super_class_of_collocation* operator-(super_class_of_collocation* _class) = 0;
	virtual super_class_of_collocation* operator-=(super_class_of_collocation* _class) = 0;
	virtual super_class_of_collocation* operator+=(super_class_of_collocation* summed_class) = 0;
	virtual super_class_of_collocation* operator*(my_double _number) = 0;
	virtual super_class_of_collocation* operator/(my_double _number) = 0;
};


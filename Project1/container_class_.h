#pragma once
#include "container_class_interface.h"
class container_class_ :
	public container_class_interface
{
public:
	//constr
	container_class_() {}
	container_class_(int counter_of_tokenizer, int k, type_of_cont_class _type_of_cont_class) : container_class_interface(counter_of_tokenizer, k, _type_of_cont_class)	{}

public:

	//methods
	virtual void give_space(int counter_of_tokenizer, int k);
	virtual void increment(int first_dimension, int second_dimension, int third_dimension);
	virtual my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension);
	virtual container_class_ pow_all(int stepen);
	virtual container_class_ sqrt_all();
	virtual class_of_first_bracket* get_vector_of_length() const;
	virtual void clear();

	//operators
	virtual class_of_first_bracket& operator[] (long int i);
	virtual container_class_ operator+(container_class_ summed_class);
	virtual container_class_ operator-(container_class_ summed_class);
	virtual container_class_& operator+=(container_class_ summed_class);
	virtual container_class_& operator-=(container_class_ summed_class);
	virtual bool operator==(container_class_ summed_class);
	virtual container_class_ operator*(my_double _koef);
	virtual container_class_ operator/(my_double _koef);
	virtual container_class_ operator/(container_class_ dividor_class);
	virtual container_class_ operator-(my_double _num);
};


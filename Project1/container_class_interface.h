#pragma once
#include "class_of_first_bracket.h"

class container_class_interface
{
public:
	//constr
	container_class_interface() {}
	container_class_interface(int counter_of_tokenizer, int k, type_of_cont_class _type_of_cont_class) : k(k), _type_of_cont_class(_type_of_cont_class) {}

	//methods
	//virtual void somphing_sheet(container_class_interface* _sheet);
	virtual void give_space(int counter_of_tokenizer, int k) = 0;
	virtual void increment(int first_dimension, int second_dimension, int third_dimension) = 0;
	virtual my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension) = 0;

	int get_counter_of_tokenizer() const;
	int get_k() const;

	virtual class_of_first_bracket* get_vector_of_length() const = 0;
	virtual void clear() = 0;

	//operators 
	virtual class_of_first_bracket& operator[] (long int i) = 0;

	static int counter_of_tokenizer;

protected:
	type_of_cont_class _type_of_cont_class;
	int k;
};
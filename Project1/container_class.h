#pragma once
#include "class_of_first_bracket.h"

class container_class
{
public:
	//constr
	container_class() {}

	//methods
	virtual void give_space(int counter_of_tokenizer, int k) = 0;
	virtual void increment(int first_dimension, int second_dimension, int third_dimension) = 0;
	virtual my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension) = 0;
	virtual int get_counter_of_tokenizer() const = 0;
	virtual int get_k() const = 0;
	//virtual container_class pow_all(int stepen) = 0; //using in sql_container_class is impossible
	//virtual container_class sqrt_all() = 0;
	virtual class_of_first_bracket* get_vector_of_length() const = 0;
	virtual int get_length() const = 0;
	//virtual bool resize(int new_size) = 0; //not used now
	virtual void clear() = 0;

	/*
	//operators 
	virtual class_of_first_bracket& operator[] (long int i) = 0;
	virtual container_class operator+(container_class summed_class) = 0;
	virtual container_class operator-(container_class summed_class) = 0;
	virtual container_class& operator+=(container_class summed_class) = 0;
	virtual container_class& operator-=(container_class summed_class) = 0;       ////////using in sql_container_class is impossible
	virtual bool operator==(container_class summed_class) = 0; 
	virtual container_class operator*(my_double _koef) = 0;
	virtual container_class operator/(my_double _koef) = 0;
	virtual container_class operator/(container_class dividor_class) = 0;
	virtual container_class operator-(my_double _num) = 0;
	*/
	//static int counter_of_tokenizer;

private:
	int k;
	class_of_first_bracket* vector_of_length;
};

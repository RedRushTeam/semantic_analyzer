#pragma once

#include "container_class.h"

class hard_container_class : public container_class
{
public:
	//constr
	hard_container_class() {}
	hard_container_class(int counter_of_tokenizer, int k) :  k(k) 
	{  
		this->give_space(counter_of_tokenizer, k);
	}

	//methods
	void give_space(int counter_of_tokenizer, int k);
	void increment(int first_dimension, int second_dimension, int third_dimension);
	my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension);
	int get_counter_of_tokenizer() const;
	int get_k() const;
	hard_container_class pow_all(int stepen);
	hard_container_class sqrt_all();
	class_of_first_bracket* get_vector_of_length() const;
	int get_length() const;
	//bool resize(int new_size);
	void clear();

	//operators
	class_of_first_bracket& operator[] (long int i);
	hard_container_class operator+(hard_container_class summed_class);
	hard_container_class operator-(hard_container_class summed_class);
	hard_container_class& operator+=(hard_container_class summed_class);
	hard_container_class& operator-=(hard_container_class summed_class);
	bool operator==(hard_container_class summed_class);
	hard_container_class operator*(my_double _koef);
	hard_container_class operator/(my_double _koef);
	hard_container_class operator/(hard_container_class dividor_class);
	hard_container_class operator-(my_double _num);

	static int counter_of_tokenizer;	

private:
	int k;
	class_of_first_bracket* vector_of_length;
};

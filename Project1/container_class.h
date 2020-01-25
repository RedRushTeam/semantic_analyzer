#pragma once
#include "class_of_first_bracket.h"

class container_class
{
public:
	//constr
	container_class() {}
	container_class(int counter_of_tokenizer, int k) : counter_of_tokenizer(counter_of_tokenizer), k(k) 
	{ this->give_space(counter_of_tokenizer, k); }

	//methods
	void give_space(int counter_of_tokenizer, int k);
	void increment(int first_dimension, int second_dimension, int third_dimension);
	my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension);
	int get_counter_of_tokenizer() const;
	int get_k() const;
	container_class pow_all(int stepen);
	container_class sqrt_all();
	vector<class_of_first_bracket> get_vector_of_length() const;
	int get_length() const;
	bool resize(int new_size);
	void clear();

	//operators
	class_of_first_bracket& operator[] (long int i);
	container_class operator+(container_class summed_class);
	container_class operator-(container_class summed_class);
	container_class& operator+=(container_class summed_class);
	container_class& operator-=(container_class summed_class);
	bool operator==(container_class summed_class);
	container_class operator*(my_double _koef);
	container_class operator/(my_double _koef);
	container_class operator/(container_class dividor_class);
	container_class operator-(my_double _num);

private:
	int counter_of_tokenizer;
	int k;
	vector<class_of_first_bracket> vector_of_length;
};

#pragma once
#include "class_of_collocation.h"

class container_class
{
public:
	container_class() {}
	container_class(int counter_of_tokenizer, int k) : counter_of_tokenizer(counter_of_tokenizer), k(k) {}

	void give_space(int counter_of_tokenizer, int k);
	void increment(int first_dimension, int second_dimension, int third_dimension);
	my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension);

private:
	int counter_of_tokenizer;
	int k;
	vector<vector<class_of_collocation>> vector_of_length;
};


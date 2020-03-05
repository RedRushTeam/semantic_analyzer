#pragma once
#include "container_class_interface.h"

class hard_container_class : public container_class_interface
{
public: 
	//constr
	hard_container_class() {}
	hard_container_class(int counter_of_tokenizer, int k, type_of_cont_class _type_of_cont_class) : container_class_interface(counter_of_tokenizer, k, _type_of_cont_class) { this->give_space(counter_of_tokenizer, k); }

	//methods
	void give_space(int counter_of_tokenizer, int k) override;
	void increment(int first_dimension, int second_dimension, int third_dimension) override;
	my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension) override;
	container_class_interface& pow_all(int stepen) override;
	container_class_interface& sqrt_all() override;
	class_of_first_bracket* get_vector_of_length() const override;
	void clear() override;

	//operators
	class_of_first_bracket& operator[] (long int i) override;
	container_class_interface& operator+(container_class_interface& summed_class) override;
	container_class_interface& operator-(container_class_interface& summed_class) override;
	container_class_interface& operator+=(container_class_interface& summed_class) override;
	container_class_interface& operator-=(container_class_interface& summed_class) override;
	bool operator==(container_class_interface& summed_class) override;
	container_class_interface& operator*(my_double _koef) override;
	container_class_interface& operator/(my_double _koef) override;
	container_class_interface& operator/(container_class_interface& dividor_class) override;
	container_class_interface& operator-(my_double _num) override;

private:
	class_of_first_bracket* vector_of_length;
};

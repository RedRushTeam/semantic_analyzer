#pragma once
#include "container_class_.h"

class hard_container_class : virtual public container_class_
{
public: 
	//constr
	hard_container_class() {}
	hard_container_class(int counter_of_tokenizer, int k, type_of_cont_class _type_of_cont_class) : container_class_(counter_of_tokenizer, k, _type_of_cont_class) { this->give_space(counter_of_tokenizer, k); }

	//methods
	void give_space(int counter_of_tokenizer, int k) override;
	void increment(int first_dimension, int second_dimension, int third_dimension) override;
	my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension) override;
	container_class_ pow_all(int stepen) override;
	container_class_ sqrt_all() override;
	class_of_first_bracket* get_vector_of_length() const override;
	void clear() override;

	//operators
	class_of_first_bracket& operator[] (long int i) override;
	container_class_ operator+(container_class_ summed_class) override;
	container_class_ operator-(container_class_ summed_class) override;
	container_class_& operator+=(container_class_ summed_class) override;
	container_class_& operator-=(container_class_ summed_class) override;
	bool operator==(container_class_ summed_class) override;
	container_class_ operator*(my_double _koef) override;
	container_class_ operator/(my_double _koef) override;
	container_class_ operator/(container_class_ dividor_class) override;
	container_class_ operator-(my_double _num) override;

private:
	class_of_first_bracket* vector_of_length;
};

#pragma once
#include "class_of_first_bracket.h"

class container_class_interface
{
public:
	//constr
	container_class_interface() {}
	container_class_interface(unsigned short int counter_of_tokenizer, char k, type_of_cont_class _type_of_cont_class, fs::path filename) : counter_of_tokenizer(counter_of_tokenizer), k(k), _type_of_cont_class(_type_of_cont_class), filename(filename)	{  }
	container_class_interface(char k, type_of_cont_class _type_of_cont_class, fs::path filename) : k(k), _type_of_cont_class(_type_of_cont_class), filename(filename) {  }

	//methods
	virtual void give_space(unsigned short int counter_of_tokenizer, char k) = 0;
	virtual void increment(int first_dimension, int second_dimension, int third_dimension) = 0;
	virtual my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension) = 0;
	virtual void download_data() = 0;
	virtual void upload_data() = 0;

	virtual container_class_interface& pow_all(int stepen) = 0;
	virtual container_class_interface& sqrt_all() = 0;

	unsigned short int get_counter_of_tokenizer() const;
	char get_k() const;
	fs::path get_path() const;
	void set_counter_of_tokenizer(unsigned short int counter_of_tokenizer);

	virtual class_of_first_bracket* get_vector_of_length() = 0;
	virtual void clear() = 0;

	//operators 
	virtual class_of_first_bracket& operator[] (long int i) = 0;
	virtual container_class_interface& operator+(container_class_interface& summed_class) = 0;
	virtual container_class_interface& operator-(container_class_interface& summed_class) = 0;
	virtual container_class_interface& operator+=(container_class_interface& summed_class) = 0;
	virtual container_class_interface& operator-=(container_class_interface& summed_class) = 0;
	virtual bool operator==(container_class_interface& summed_class) = 0;
	virtual container_class_interface& operator*(my_double _koef) = 0;
	virtual container_class_interface& operator/(my_double _koef) = 0;
	virtual container_class_interface& operator/(container_class_interface& dividor_class) = 0;
	virtual container_class_interface& operator-(my_double _num) = 0;

	unsigned short int counter_of_tokenizer;

protected:
	fs::path filename;
	type_of_cont_class _type_of_cont_class;
	char k;
};
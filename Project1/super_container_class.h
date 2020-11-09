#pragma once
<<<<<<< Updated upstream
#include "parser.h"
#include "class_of_first_bracket.h"
=======
//#include "parser.h"
#include "super_class_of_first_bracket.h"
>>>>>>> Stashed changes
#define OUT_PATH "A:\\text_output\\"

class super_container_class
{
public:
	//constr
	super_container_class() {}
	super_container_class(unsigned short int counter_of_tokenizer, char k, type_of_cont_class _type_of_cont_class, fs::path filename) : counter_of_tokenizer(counter_of_tokenizer), k(k), _type_of_cont_class(_type_of_cont_class), filename(filename) {}

	super_container_class(char k, type_of_cont_class _type_of_cont_class, fs::path filename) : k(k), _type_of_cont_class(_type_of_cont_class), filename(filename) {}


	~super_container_class() {}
	
	//methods
	virtual void give_space(unsigned short int counter_of_tokenizer, int k) = 0;
	virtual void increment(int first_dimension, int second_dimension, int third_dimension) = 0;
	virtual my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension) = 0;
	virtual super_container_class* pow_all(int stepen) = 0;
	virtual super_container_class* sqrt_all() = 0;
<<<<<<< Updated upstream
	virtual class_of_first_bracket* get_vector_of_length() = 0;
=======
	virtual super_class_of_first_bracket* get_vector_of_length() = 0;	//govno
>>>>>>> Stashed changes
	virtual void clear() = 0;
	virtual void download_data() = 0;
	virtual void upload_data() = 0;
	virtual unsigned short int get_counter_of_tokenizer() const = 0;
	virtual int get_k() const = 0;
	virtual fs::path get_path() const = 0;
	virtual void set_counter_of_tokenizer(unsigned short int counter_of_tokenizer) = 0;
	virtual void swap_is_download_dataed() = 0;

	//operators
	virtual class_of_first_bracket& operator[] (long int i) = 0;
	virtual super_container_class* operator+(super_container_class* summed_class) = 0;
	virtual super_container_class* operator-(super_container_class* summed_class) = 0;
	virtual void operator+=(super_container_class* summed_class) = 0;
	virtual super_container_class* operator-=(super_container_class* summed_class) = 0;
	virtual bool operator==(super_container_class* summed_class) = 0;
	virtual super_container_class* operator*(my_double _koef) = 0;
	virtual super_container_class* operator/(my_double _koef) = 0;
	virtual super_container_class* operator/(super_container_class* dividor_class) = 0;
	virtual super_container_class* operator-(my_double _num) = 0;
	//super_container_class operator=(super_container_class right_class);

	static unsigned short int counter_of_linked_container_class;
	unsigned short int counter_of_tokenizer;
protected:

	bool is_download_dataed = 0;
	fs::path filename;
	type_of_cont_class _type_of_cont_class;
	int k;



};
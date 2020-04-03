#pragma once
#include "container_class_interface.h"
#include "parser.h"
//#define OUT_PATH "A:\\text_output\\"
#define OUT_PATH "C:\\Users\\fortunati\\Desktop\\text_output\\"

class hard_container_class
{
public: 
	//constr
	hard_container_class() {}
	hard_container_class(unsigned short int counter_of_tokenizer, char k, type_of_cont_class _type_of_cont_class, fs::path filename) : counter_of_tokenizer(counter_of_tokenizer), k(k), _type_of_cont_class(_type_of_cont_class), filename(filename) {
		++counter_of_linked_container_class;
	}
	
	hard_container_class(char k, type_of_cont_class _type_of_cont_class, fs::path filename) : k(k), _type_of_cont_class(_type_of_cont_class), filename(filename) {
		++counter_of_linked_container_class;
	}

	~hard_container_class() {
	}

	// Унаследовано через container_class_interface
	//methods
	void give_space(unsigned short int counter_of_tokenizer, int k) ;
	void increment(int first_dimension, int second_dimension, int third_dimension) ;
	my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension) ;
	hard_container_class pow_all(int stepen) ;
	hard_container_class sqrt_all() ;
	class_of_first_bracket* get_vector_of_length() ;
	void clear() ;
	virtual void download_data() ;
	virtual void upload_data() ;
	unsigned short int get_counter_of_tokenizer() const;
	int get_k() const;
	fs::path get_path() const;
	void set_counter_of_tokenizer(unsigned short int counter_of_tokenizer);


	//operators
	class_of_first_bracket& operator[] (long int i) ;
	hard_container_class operator+(hard_container_class summed_class);
	hard_container_class operator-(hard_container_class summed_class);
	hard_container_class operator+=(hard_container_class summed_class);
	hard_container_class operator-=(hard_container_class summed_class);
	bool operator==(hard_container_class summed_class);
	hard_container_class operator*(my_double _koef);
	hard_container_class operator/(my_double _koef);
	hard_container_class operator/(hard_container_class dividor_class);
	hard_container_class operator-(my_double _num);

	static unsigned short int counter_of_linked_container_class;
	unsigned short int counter_of_tokenizer;
private:
	class_of_first_bracket* vector_of_length;
	bool is_download_dataed = 0;
	fs::path filename;
	type_of_cont_class _type_of_cont_class;
	int k;
};
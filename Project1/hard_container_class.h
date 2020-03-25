#pragma once
#include "container_class_interface.h"
#include "parser.h"
//#define OUT_PATH "A:\\text_output\\"
#define OUT_PATH "C:\\Users\\fortunati\\Desktop\\text_output\\"

class hard_container_class : public container_class_interface
{
public: 
	//constr
	hard_container_class() {}
	hard_container_class(unsigned short int counter_of_tokenizer, char k, type_of_cont_class _type_of_cont_class, fs::path filename) : container_class_interface(counter_of_tokenizer, k, _type_of_cont_class, filename) {
		++counter_of_linked_container_class;
	}
	
	hard_container_class(char k, type_of_cont_class _type_of_cont_class, fs::path filename) : container_class_interface(k, _type_of_cont_class, filename) {
		++counter_of_linked_container_class;
	}

	~hard_container_class() {
		ofstream matrix(OUT_PATH + to_string(this->counter_of_linked_container_class) + ".txt", ios::trunc);
	}

	// Унаследовано через container_class_interface
	//methods
	void give_space(unsigned short int counter_of_tokenizer, int k) override;
	void increment(int first_dimension, int second_dimension, int third_dimension) override;
	my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension) override;
	container_class_interface& pow_all(int stepen) override;
	container_class_interface& sqrt_all() override;
	class_of_first_bracket* get_vector_of_length() override;
	void clear() override;
	virtual void download_data() override;
	virtual void upload_data() override;


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

	static unsigned short int counter_of_linked_container_class;

private:
	class_of_first_bracket* vector_of_length;
	bool is_download_dataed = 0;
};
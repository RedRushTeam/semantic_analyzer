#include "super_container_class.h"

unsigned short int super_container_class::get_counter_of_tokenizer() const
{
	return this->counter_of_tokenizer;
}

int super_container_class::get_k() const
{
	return this->k;
}

fs::path super_container_class::get_path() const
{
	return this->filename;
}

void super_container_class::set_counter_of_tokenizer(unsigned short int counter_of_tokenizer)
{
	this->counter_of_tokenizer = counter_of_tokenizer;
}
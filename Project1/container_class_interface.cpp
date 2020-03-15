#include "container_class_interface.h"

unsigned short int container_class_interface::get_counter_of_tokenizer() const
{
	return this->counter_of_tokenizer;
}

char container_class_interface::get_k() const
{
	return this->k;
}

fs::path container_class_interface::get_path() const
{
	return this->filename;
}

void container_class_interface::set_counter_of_tokenizer(unsigned short int counter_of_tokenizer)
{
	this->counter_of_tokenizer = counter_of_tokenizer;
}

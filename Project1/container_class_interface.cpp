#include "container_class_interface.h"

int container_class_interface::counter_of_tokenizer = 0;

int container_class_interface::get_counter_of_tokenizer() const
{
	return this->counter_of_tokenizer;
}

int container_class_interface::get_k() const
{
	return this->k;
}
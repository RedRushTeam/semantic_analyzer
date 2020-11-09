#pragma once
#include "class_of_first_bracket.h"

class class_of_first_bracket_for_sparce_container_class : public super_class_of_first_bracket
{
public:
	//constr
	class_of_first_bracket_for_sparce_container_class() {
		this->vector_of_length = new class_of_collocation_for_sparce_cont_class();
	}

	//methods
	void give_space(int counter_of_tokenizer, int k) override;
	void clear() override;
	void set_first_bracket_counter(int i) override;

	//operators
	super_class_of_collocation& operator[](long int i) override;	//new children there

private:
	super_class_of_collocation* vector_of_length;
};


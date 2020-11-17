#pragma once
class super_class_of_first_bracket
{
public:
	//methods
	virtual void give_space(int counter_of_tokenizer, int k);
	virtual void clear();
	virtual void set_first_bracket_counter(int i);

	//operators
	super_class_of_first_bracket& operator[](long int i);


	int counter_of_tokenizer;
};


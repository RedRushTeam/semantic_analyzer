#pragma once
class super_class_of_collocation
{
public:

	//methods
	virtual void give_space(int k);
	virtual void increment(int third_demention);
	virtual my_double get_count_of_concret_collocation(int third_demention);
	//my_double* get_vect_of_collocation() { return vect_of_collocation; };
	//virtual void set_vect_of_collocation(my_double* massiv, int k);
	virtual void pow_all(int stepen);
	virtual void sqrt_all();
	virtual void clear();

	//operators
	virtual my_double& operator[](long int i);
	virtual class_of_collocation operator +(class_of_collocation summed_class);
	virtual class_of_collocation operator -(class_of_collocation _class);
	virtual class_of_collocation operator -=(class_of_collocation _class);
	virtual class_of_collocation operator +=(class_of_collocation summed_class);
	virtual class_of_collocation operator *(my_double _number);
	virtual class_of_collocation operator /(my_double _number);
};


#include "class_of_collocation.h"

void class_of_collocation::give_space(int k)
{
	this->vect_of_collocation = new my_double[2 * k + 2];
	for (auto i = 0; i < (2 * k + 2); ++i)
		vect_of_collocation[i] = 0;
}

void class_of_collocation::increment(int third_demention)
{
	vect_of_collocation[third_demention]++;
}

my_double class_of_collocation::get_count_of_concret_collocation(int third_demention)
{
	return this->vect_of_collocation[third_demention];
}

void class_of_collocation::pow_all(int stepen)
{
	for (int i = -GAP - 1; i <= GAP; ++i)
		this->vect_of_collocation[i + (GAP + 1)] = pow(this->vect_of_collocation[i + (GAP + 1)], stepen);
}

void class_of_collocation::sqrt_all()
{
	for (int i = -GAP - 1; i <= GAP; ++i) 
		this->vect_of_collocation[i + (GAP + 1)] = sqrt(this->vect_of_collocation[i + (GAP + 1)]);
}

void class_of_collocation::clear()
{
	delete[] vect_of_collocation;
	this->vect_of_collocation = NULL;
}

my_double& class_of_collocation::operator[](long int i)
{
	return this->vect_of_collocation[i + GAP + 1];
}

class_of_collocation class_of_collocation::operator+(class_of_collocation summed_class)
{
	class_of_collocation cl_for_return(GAP);
	cl_for_return.give_space(GAP);
	for (int i = -GAP - 1; i <= GAP; ++i) {
		cl_for_return[i] = (*this)[i] + summed_class[i];
	}

	return cl_for_return;
}

class_of_collocation class_of_collocation::operator-(class_of_collocation _class)
{
	class_of_collocation cl_for_return(GAP);
	cl_for_return.give_space(GAP);
	for (int i = -GAP - 1; i <= GAP; ++i) {
		if (this->vect_of_collocation[i] - _class[i] >= 0)
			cl_for_return[i] = (*this)[i] - _class[i];
		else
			cl_for_return[i] = 0;
	}

	return cl_for_return;
}

class_of_collocation class_of_collocation::operator-=(class_of_collocation _class)
{
	for (int i = -GAP - 1; i <= GAP; ++i) {
		if ((*this)[i] - _class[i] >= 0)
			(*this)[i] = (*this)[i] - _class[i];
		else
			(*this)[i] = 0;
	}

	return *this;
}

class_of_collocation class_of_collocation::operator+=(class_of_collocation summed_class)
{
	for (int i = -GAP - 1; i <= GAP; ++i) {
		(*this)[i] = (*this)[i] + summed_class[i];
	}

	return *this;
}

class_of_collocation class_of_collocation::operator*(my_double _number)
{
	class_of_collocation cl_for_return(GAP);
	cl_for_return.give_space(GAP);
	for (int i = -GAP - 1; i <= GAP; ++i) {
		cl_for_return[i] = (*this)[i] * _number;
	}

	return cl_for_return;
}

class_of_collocation class_of_collocation::operator/(my_double _number)
{
	class_of_collocation cl_for_return(GAP);
	cl_for_return.give_space(GAP);
	for (int i = -GAP - 1; i <= GAP; ++i) {
		cl_for_return[i] = (*this)[i] / _number;
	}

	return cl_for_return;
}

void class_of_collocation::set_vect_of_collocation(my_double* massiv, int k)
{
	for (auto i = 0; i < (2 * k + 2); ++i)
		vect_of_collocation[i] = massiv[i];
}
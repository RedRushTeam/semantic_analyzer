#include "class_of_collocation.h"

void class_of_collocation::give_space(char k)
{
	int k1 = k;
	this->vect_of_collocation = new my_double[2 * k1 + 2];
	for (auto i = 0; i < (2 * k1 + 2); ++i) {
		int sheet = 0;
		vect_of_collocation[i] = 0;
	}
}

void class_of_collocation::increment(int third_demention)
{
	vect_of_collocation[third_demention]++;
}

my_double class_of_collocation::get_count_of_concret_collocation(int third_demention)
{
	return this->vect_of_collocation[third_demention];
}

class_of_collocation class_of_collocation::pow_all(int stepen)
{
	class_of_collocation cl_for_return(GAP);

	for (int i = -GAP - 1; i <= GAP; ++i) {
		cl_for_return[i] = 
			pow(this->vect_of_collocation[i + (GAP + 1)], stepen);
	}

	return cl_for_return;
}

class_of_collocation class_of_collocation::sqrt_all()
{
	class_of_collocation cl_for_return(GAP);

	for (int i = -GAP-1; i <= GAP; ++i) {
		cl_for_return[i] = sqrt(this->vect_of_collocation[i + (GAP + 1)]);
	}

	return cl_for_return;
}

my_double& class_of_collocation::operator[](long int i)
{
	return this->vect_of_collocation[i + (GAP + 1)];
}

class_of_collocation class_of_collocation::operator+(class_of_collocation& summed_class)
{
	class_of_collocation cl_for_return(GAP);

	for (int i = 0; i < (2 * GAP + 2); ++i) {
		cl_for_return[i] = this->vect_of_collocation[i] + summed_class[i];
	}

	return cl_for_return;
}

class_of_collocation class_of_collocation::operator-(class_of_collocation& _class)
{
	class_of_collocation cl_for_return(GAP);

	for (int i = 0; i < (2 * GAP + 2); ++i) {
		if (this->vect_of_collocation[i] - _class[i] >= 0)
			cl_for_return[i] = this->vect_of_collocation[i] - _class[i];
		else
			cl_for_return[i] = 0;
	}

	return cl_for_return;
}

class_of_collocation& class_of_collocation::operator-=(class_of_collocation& _class)
{
	for (int i = 0; i < (2 * GAP + 2); ++i) {
		if (this->vect_of_collocation[i] - _class[i] >= 0)
			this->vect_of_collocation[i] = this->vect_of_collocation[i] - _class[i];
		else
			this->vect_of_collocation[i] = 0;
	}

	return *this;
}

class_of_collocation& class_of_collocation::operator+=(class_of_collocation& summed_class)
{
	for (int i = 0; i < (2 * GAP + 2); ++i) {
		this->vect_of_collocation[i] = this->vect_of_collocation[i] + summed_class[i];
	}

	return *this;
}

class_of_collocation class_of_collocation::operator*(my_double _number)
{
	class_of_collocation cl_for_return(GAP);

	for (int i = 0; i < (2 * GAP + 2); ++i) {
		cl_for_return[i] = this->vect_of_collocation[i] * _number;
	}

	return cl_for_return;
}

class_of_collocation class_of_collocation::operator/(my_double _number)
{
	class_of_collocation cl_for_return(GAP);

	for (int i = 0; i < (2 * GAP + 2); ++i) {
		cl_for_return[i] = this->vect_of_collocation[i] / _number;
	}

	return cl_for_return;
}

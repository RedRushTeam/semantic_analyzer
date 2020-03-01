#include "class_of_collocation.h"

void class_of_collocation::give_space(int k)
{
	
	//vect_of_collocation.resize(2 * k + 2);
	//fill(vect_of_collocation.begin(), vect_of_collocation.end(), 0);
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
	/*if (this->vect_of_collocation.size() != summed_class.vect_of_collocation.size())
		nullptr;	*/																		//nuzno sdelat' vihod iz funktii, dumayu pri pomoshi //throw

	class_of_collocation cl_for_return(GAP);

	for (int i = 0; i < (2 * GAP + 2)/*this->vect_of_collocation.size()*/; ++i) {
		cl_for_return[i] = this->vect_of_collocation[i] + summed_class[i];
	}

	return cl_for_return;
}

class_of_collocation class_of_collocation::operator-(class_of_collocation& _class)
{
	/*if (this->vect_of_collocation.size() != _class.vect_of_collocation.size())
		nullptr;*/																			//nuzno sdelat' vihod iz funktii, dumayu pri pomoshi //throw

	class_of_collocation cl_for_return(GAP);

	for (int i = 0; i < (2 * GAP + 2)/*this->vect_of_collocation.size()*/; ++i) {
		if (this->vect_of_collocation[i] - _class[i] >= 0)
			cl_for_return[i] = this->vect_of_collocation[i] - _class[i];
		else
			cl_for_return[i] = 0;
	}

	return cl_for_return;
}

class_of_collocation& class_of_collocation::operator-=(class_of_collocation& _class)
{
	/*if (this->vect_of_collocation.size() != _class.vect_of_collocation.size())
		nullptr;*/																			//nuzno sdelat' vihod iz funktii, dumayu pri pomoshi //throw

	for (int i = 0; i < (2 * GAP + 2)/*this->vect_of_collocation.size()*/; ++i) {
		if (this->vect_of_collocation[i] - _class[i] >= 0)
			this->vect_of_collocation[i] = this->vect_of_collocation[i] - _class[i];
		else
			this->vect_of_collocation[i] = 0;
	}

	return *this;
}

class_of_collocation& class_of_collocation::operator+=(class_of_collocation& summed_class)
{
	/*if (this->vect_of_collocation.size() != summed_class.vect_of_collocation.size())
		nullptr;*/																			//nuzno sdelat' vihod iz funktii, dumayu pri pomoshi //throw

	for (int i = 0; i < (2 * GAP + 2)/*this->vect_of_collocation.size()*/; ++i) {
		this->vect_of_collocation[i] = this->vect_of_collocation[i] + summed_class[i];
	}

	return *this;
}

class_of_collocation class_of_collocation::operator*(my_double _number)
{
	class_of_collocation cl_for_return(GAP);

	for (int i = 0; i < (2 * GAP + 2)/*this->vect_of_collocation.size()*/; ++i) {
		cl_for_return[i] = this->vect_of_collocation[i] * _number;
	}

	return cl_for_return;
}

class_of_collocation class_of_collocation::operator/(my_double _number)
{
	class_of_collocation cl_for_return(GAP);

	for (int i = 0; i < (2 * GAP + 2)/*this->vect_of_collocation.size()*/; ++i) {
		cl_for_return[i] = this->vect_of_collocation[i] / _number;
	}

	return cl_for_return;
}

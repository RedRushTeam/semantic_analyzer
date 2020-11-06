#pragma once
#include "list_of_types.h"
#include "super_class_of_collocation.h"
//using namespace boost::numeric::ublas;
class class_of_collocation : public super_class_of_collocation
{
public:
	//constr
	class_of_collocation() {}
	class_of_collocation(int k) {
		
	}
	/*class_of_collocation(class_of_collocation& right_value) {
		give_space(right_value.k);                                               //fuking k
		for (auto i = 0; i < (2 * k + 2); ++i)
			vect_of_collocation[i] = right_value.vect_of_collocation[i];
	}*/ 


	//methods
	void give_space(int k);
	void increment(int third_demention);
	my_double get_count_of_concret_collocation(int third_demention);
	my_double* get_vect_of_collocation() { return vect_of_collocation; };
	void set_vect_of_collocation(my_double* massiv, int k);
	void pow_all(int stepen);
	void sqrt_all();
	void clear();

	//operators
	my_double& operator[](long int i);
	class_of_collocation operator +(class_of_collocation summed_class);
	class_of_collocation operator -(class_of_collocation _class);
	class_of_collocation operator -=(class_of_collocation _class);
	class_of_collocation operator +=(class_of_collocation summed_class);
	class_of_collocation operator *(my_double _number);
	class_of_collocation operator /(my_double _number);
private:
	my_double* vect_of_collocation;
	//mapped_matrix<my_double>* vect_of_sparce_collocation;
};

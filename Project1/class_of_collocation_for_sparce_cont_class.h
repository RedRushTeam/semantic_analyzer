#pragma once
#include "super_container_class.h"

class class_of_collocation_for_sparce_cont_class : public super_class_of_collocation
{
public:
	//methods
	void give_space(int k);
	void increment(int third_demention);
	my_double get_count_of_concret_collocation(int third_demention);
	//my_double* get_vect_of_collocation() { return vect_of_collocation; };
	//void set_vect_of_collocation(my_double* massiv, int k);
	void pow_all(int stepen);
	void sqrt_all();
	void clear();
	void set_first_bracket(int _first_bracket);
	void set_second_bracket(int _second_bracket);
	int get_second_bracket() const;
	int get_first_bracket() const;

	//operators
	my_double& operator[](long int i);
	class_of_collocation operator +(class_of_collocation summed_class);
	class_of_collocation operator -(class_of_collocation _class);
	class_of_collocation operator -=(class_of_collocation _class);
	class_of_collocation operator +=(class_of_collocation summed_class);
	class_of_collocation operator *(my_double _number);
	class_of_collocation operator /(my_double _number);


private:
	map<pair<int, pair<int, int>>, my_double> _scary_map;
	int _first_bracket = -1;
	int _second_bracket = -1;

};


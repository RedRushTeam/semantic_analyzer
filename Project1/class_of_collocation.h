#pragma once
#include "list_of_types.h"
class class_of_collocation
{
public:
	class_of_collocation() {}
	class_of_collocation(int k) : k(k) { vect_of_collocation.resize(2 * k + 2); }

	void give_space(int k);
	void increment(int third_demention);
	my_double get_count_of_concret_collocation(int third_demention);

private:
	int k;
	vector<my_double> vect_of_collocation;
};


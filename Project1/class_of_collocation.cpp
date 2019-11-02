#include "class_of_collocation.h"

void class_of_collocation::give_space(int k)
{
	vect_of_collocation.resize(2 * k + 2);
	fill(vect_of_collocation.begin(), vect_of_collocation.end(), 0);
}

void class_of_collocation::increment(int third_demention)
{
	vect_of_collocation[third_demention]++;
}

my_double class_of_collocation::get_count_of_concret_collocation(int third_demention)
{
	return this->vect_of_collocation[third_demention];
}

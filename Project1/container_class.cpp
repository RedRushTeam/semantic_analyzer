#include "container_class.h"

void container_class::give_space(int counter_of_tokenizer, int k)
{
	vector_of_length.resize(counter_of_tokenizer);
	this->counter_of_tokenizer = counter_of_tokenizer;
	this->k = k;

	for (int i = 0; i < counter_of_tokenizer; ++i) {
		vector_of_length[i].resize(counter_of_tokenizer);

		for (int j = 0; j < counter_of_tokenizer; ++j)
			vector_of_length[i][j].give_space(k);
	}
}

void container_class::increment(int first_dimension, int second_dimension, int third_dimension)
{
	vector_of_length[first_dimension][second_dimension].increment(third_dimension);
}

my_double container_class::get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension)
{
	return this->vector_of_length[first_dimension][second_dimension].get_count_of_concret_collocation(third_dimension);
}

int container_class::get_counter_of_tokenizer() const
{
	return this->counter_of_tokenizer;
}

int container_class::get_k() const
{
	return this->k;
}

container_class container_class::pow_all(int stepen)
{
	container_class cl_for_return(counter_of_tokenizer, k);
	cl_for_return.give_space(counter_of_tokenizer, k);

	for (int i = 0; i < this->vector_of_length.size(); ++i)
		cl_for_return[i] = this->vector_of_length[i].pow_all(stepen);
	
	return cl_for_return;
}

container_class container_class::sqrt_all()
{
	container_class cl_for_return(counter_of_tokenizer, k);
	cl_for_return.give_space(counter_of_tokenizer, k);

	for (int i = 0; i < this->vector_of_length.size(); ++i)
		cl_for_return[i] = this->vector_of_length[i].sqrt_all();

	return cl_for_return;
}

class_of_first_bracket& container_class::operator[](long int i)
{
	return this->vector_of_length[i];
}

container_class container_class::operator+(container_class summed_class)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < vector_of_length.size(); ++i)
		for (auto j = 0; j < vector_of_length.size(); ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					ret[i][j][p] = (*this)[i][j][p] + summed_class[i][j][p];
	return ret;
}

container_class container_class::operator-(container_class _class)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < vector_of_length.size(); ++i)
		for (auto j = 0; j < vector_of_length.size(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] - _class[i][j][p];
	return ret;
}

container_class container_class::operator*(my_double _koef)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < vector_of_length.size(); ++i)
		for (auto j = 0; j < vector_of_length.size(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] * _koef;
	return ret;
}

container_class container_class::operator/(my_double _koef)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < vector_of_length.size(); ++i)
		for (auto j = 0; j < vector_of_length.size(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] / _koef;
	return ret;
}

container_class& container_class::operator+=(container_class summed_class)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < vector_of_length.size(); ++i)
		for (auto j = 0; j < vector_of_length.size(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				(*this)[i][j][p] = (*this)[i][j][p] + summed_class[i][j][p];
	return *this;
}

container_class& container_class::operator-=(container_class summed_class)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < vector_of_length.size(); ++i)
		for (auto j = 0; j < vector_of_length.size(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				(*this)[i][j][p] = (*this)[i][j][p] - summed_class[i][j][p];
	return *this;
}

container_class container_class::operator/(container_class dividor_class)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < vector_of_length.size(); ++i)
		for (auto j = 0; j < vector_of_length.size(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] / dividor_class[i][j][p];
	return ret;
}

vector<class_of_first_bracket> container_class::get_vector_of_length() const
{
	return this->vector_of_length;
}

int container_class::get_length() const
{
	return this->vector_of_length.size();
}

/*bool container_class::resize(int new_size)		////////todo////////
{
	if(this->vector_of_length.size() >= new_size)
		return false;
	else {
		
		for (auto obj : this->vector_of_length) {
			class_of_collocation cl_for_push;
			cl_for_push.give_space(GAP);
			obj.push_back(cl_for_push);
		}
	}
}*/

container_class container_class::operator-(my_double _num)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < vector_of_length.size(); ++i)
		for (auto j = 0; j < vector_of_length.size(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] - _num;
	return ret;
}
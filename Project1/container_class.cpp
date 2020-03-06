#include "container_class.h"

int container_class::counter_of_tokenizer = 0;

void container_class::give_space(int counter_of_tokenizer, int k)
{
	this->vector_of_length = new class_of_first_bracket [counter_of_tokenizer];
	
	class_of_first_bracket::counter_of_tokenizer = counter_of_tokenizer;
	//vector_of_length.resize(counter_of_tokenizer);
	//this->counter_of_tokenizer = counter_of_tokenizer;
	this->k = k;
	
	/////////////////////////////////////////////

	/*size_t size = 0;
	for (vector<class_of_first_bracket>::const_iterator cit = vector_of_length.begin(); cit != vector_of_length.end(); ++cit) {
		size += sizeof(*cit);
	}*/

	//ves vneshnego vectora po 32 bita 

	//cout << endl << size << endl;

	//////////////////////////////////////////

	for (int i = 0; i < counter_of_tokenizer; ++i)
		vector_of_length[i].give_space(k);

	////////////////////////////////////////

	/*auto sheet = vector_of_length[0].get_vector_of_length();

	size_t _size = 0;
	for (vector<class_of_collocation>::const_iterator cit = sheet.begin(); cit != sheet.end(); ++cit) {
		_size += sizeof(*cit);
	}

	cout << endl << _size << endl;*/

	//ves vnutrennego vectora po 32 bita 

	/////////////////////////////////////////

	/*for (int i = 0; i < counter_of_tokenizer; ++i)
		for (int j = 0; j < counter_of_tokenizer; ++j)
			vector_of_length[i][j].give_space(k);*/

	///////////////////////////////////////////

	/*auto sheet__ = vector_of_length[0][0].get_vect_of_collocation();

	size_t _size_ = 0;

	for (vector<float>::const_iterator cit = sheet__.begin(); cit != sheet__.end(); ++cit) {
		_size_ += sizeof(*cit);
	}

	cout << endl << _size_ << endl;*/

	//ves vnutrennego_vnutrennego vectora po 32 bita dlya GAP == 3

	//obsh 32*32*32* counter of tokenizer

	//int i = 0;

	//////////////////////////////////////////////
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

	for (int i = 0; i < this->counter_of_tokenizer/*this->vector_of_length.size()*/; ++i) //использование counter_of_tokenizer
		cl_for_return[i] = this->vector_of_length[i].pow_all(stepen);
	
	return cl_for_return;
}

container_class container_class::sqrt_all()
{
	container_class cl_for_return(counter_of_tokenizer, k);
	cl_for_return.give_space(counter_of_tokenizer, k);

	for (int i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
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
	for (int i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
		for (int j = 0; j < counter_of_tokenizer/*this->vector_of_length.size()*/; ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					ret[i][j][p] = (*this)[i][j][p] + summed_class[i][j][p];
	return ret;
}

container_class container_class::operator-(container_class _class)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
		for (auto j = 0; j < counter_of_tokenizer/*this->vector_of_length.size()*/; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] - _class[i][j][p];
	return ret;
}

container_class container_class::operator*(my_double _koef)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
		for (auto j = 0; j < counter_of_tokenizer/*this->vector_of_length.size()*/; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] * _koef;
	return ret;
}

container_class container_class::operator/(my_double _koef)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
		for (auto j = 0; j < counter_of_tokenizer/*this->vector_of_length.size()*/; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] / _koef;
	return ret;
}

container_class& container_class::operator+=(container_class summed_class)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
		for (auto j = 0; j < counter_of_tokenizer/*this->vector_of_length.size()*/; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				(*this)[i][j][p] = (*this)[i][j][p] + summed_class[i][j][p];
	return *this;
}

container_class& container_class::operator-=(container_class summed_class)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
		for (auto j = 0; j < counter_of_tokenizer/*this->vector_of_length.size()*/; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				(*this)[i][j][p] = (*this)[i][j][p] - summed_class[i][j][p];
	return *this;
}

bool container_class::operator==(container_class summed_class)
{
	for (auto q = 0; q < this->get_length(); ++q)
		for (auto j = 0; j < this->get_length(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				if(this->vector_of_length[q][q][p] != summed_class[q][q][p])
					return false;
	return true;
}

container_class container_class::operator/(container_class dividor_class)
{
	container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
		for (auto j = 0; j < counter_of_tokenizer/*this->vector_of_length.size()*/; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] / dividor_class[i][j][p];
	return ret;
}

/*vector<class_of_first_bracket>*/class_of_first_bracket* container_class::get_vector_of_length() const
{
	return this->vector_of_length;
}

int container_class::get_length() const
{
	return this->counter_of_tokenizer/*this->vector_of_length.size()*/;
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
	for (auto i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i)
		for (auto j = 0; j < counter_of_tokenizer/*this->vector_of_length.size()*/; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] - _num;
	return ret;
}

void container_class::clear()
{
	for (auto i = 0; i < counter_of_tokenizer/*this->vector_of_length.size()*/; ++i) {
		auto tmp = vector_of_length[i].get_vector_of_length();
		for (auto j = 0; j < counter_of_tokenizer; j++) {
			auto tmp1 = tmp[j].get_vect_of_collocation();
			delete[] tmp1;
		}
		delete[] tmp;
	}
	//this->vector_of_length.clear();
	delete[] vector_of_length;
}
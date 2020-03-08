#include "hard_container_class.h"

#define OUT_PATH "A:\\text_output"

unsigned short int hard_container_class::counter_of_linked_container_class = 0;

void hard_container_class::give_space(unsigned short int counter_of_tokenizer, char k)
{
	this->vector_of_length = new class_of_first_bracket [counter_of_tokenizer];
	
	class_of_first_bracket::counter_of_tokenizer = counter_of_tokenizer;
	this->k = k;

	for (int i = 0; i < counter_of_tokenizer; ++i)
		vector_of_length[i].give_space(k);
}

void hard_container_class::increment(int first_dimension, int second_dimension, int third_dimension)
{
	vector_of_length[first_dimension][second_dimension].increment(third_dimension);
}

container_class_interface& hard_container_class::pow_all(int stepen)
{
	hard_container_class cl_for_return(counter_of_tokenizer, k, hard_container_class_);
	cl_for_return.give_space(counter_of_tokenizer, k);

	for (int i = 0; i < this->counter_of_tokenizer; ++i) 
		cl_for_return[i] = this->vector_of_length[i].pow_all(stepen);
	
	return cl_for_return;
}

container_class_interface& hard_container_class::sqrt_all()
{
	hard_container_class cl_for_return(counter_of_tokenizer, k, hard_container_class_);
	cl_for_return.give_space(counter_of_tokenizer, k);

	for (int i = 0; i < counter_of_tokenizer; ++i)
		cl_for_return[i] = this->vector_of_length[i].sqrt_all();

	return cl_for_return;
}

class_of_first_bracket& hard_container_class::operator[](long int i)
{
	return this->vector_of_length[i];
}

container_class_interface& hard_container_class::operator+(container_class_interface& summed_class)
{
	hard_container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (int i = 0; i < counter_of_tokenizer; ++i)
		for (int j = 0; j < counter_of_tokenizer; ++j)
				for (auto p = -GAP - 1; p <= GAP; ++p)
					ret[i][j][p] = (*this)[i][j][p] + summed_class[i][j][p];
	return ret;
}

container_class_interface& hard_container_class::operator-(container_class_interface& _class)
{
	hard_container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer; ++i)
		for (auto j = 0; j < counter_of_tokenizer; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] - _class[i][j][p];
	return ret;
}

container_class_interface& hard_container_class::operator*(my_double _koef)
{
	hard_container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer; ++i)
		for (auto j = 0; j < counter_of_tokenizer; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] * _koef;
	return ret;
}

container_class_interface& hard_container_class::operator/(my_double _koef)
{
	hard_container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer; ++i)
		for (auto j = 0; j < counter_of_tokenizer; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] / _koef;
	return ret;
}

container_class_interface& hard_container_class::operator+=(container_class_interface& summed_class)
{
	hard_container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer; ++i)
		for (auto j = 0; j < counter_of_tokenizer; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				(*this)[i][j][p] = (*this)[i][j][p] + summed_class[i][j][p];
	return *this;
}

container_class_interface& hard_container_class::operator-=(container_class_interface& summed_class)
{
	hard_container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer; ++i)
		for (auto j = 0; j < counter_of_tokenizer; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				(*this)[i][j][p] = (*this)[i][j][p] - summed_class[i][j][p];
	return *this;
}

bool hard_container_class::operator==(container_class_interface& summed_class)
{
	for (auto q = 0; q < this->get_counter_of_tokenizer(); ++q)
		for (auto j = 0; j < this->get_counter_of_tokenizer(); ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				if(this->vector_of_length[q][q][p] != summed_class[q][q][p])
					return false;
	return true;
}

container_class_interface& hard_container_class::operator/(container_class_interface& dividor_class)
{
	hard_container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer; ++i)
		for (auto j = 0; j < counter_of_tokenizer; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] / dividor_class[i][j][p];
	return ret;
}

class_of_first_bracket* hard_container_class::get_vector_of_length() const
{
	return this->vector_of_length;
}

container_class_interface& hard_container_class::operator-(my_double _num)
{
	hard_container_class ret;
	ret.give_space(this->counter_of_tokenizer, this->k);
	for (auto i = 0; i < counter_of_tokenizer; ++i)
		for (auto j = 0; j < counter_of_tokenizer; ++j)
			for (auto p = -GAP - 1; p <= GAP; ++p)
				ret[i][j][p] = (*this)[i][j][p] - _num;
	return ret;
}

void hard_container_class::clear()
{
	for (auto i = 0; i < counter_of_tokenizer; ++i) {
		auto tmp = vector_of_length[i].get_vector_of_length();
		for (auto j = 0; j < counter_of_tokenizer; j++) {
			auto tmp1 = tmp[j].get_vect_of_collocation();
			delete[] tmp1;
		}
		delete[] tmp;
	}
	delete[] vector_of_length;
}

my_double hard_container_class::get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension)
{
	return this->vector_of_length[first_dimension][second_dimension].get_count_of_concret_collocation(third_dimension);
}

fs::path hard_container_class::get_path() const
{
	auto input_path = fs::current_path() / "text_data";
	return input_path;
}

void hard_container_class::download()
{
	this->give_space(this->counter_of_tokenizer, this->get_k());

	ifstream matrix(OUT_PATH + to_string(this->counter_of_linked_container_class) + ".txt");	//заменить это на std::filesystem

	while (!matrix.eof()) {
		string line;
		auto np = line.npos;
		std::getline(matrix, line);
		for (int i = GAP - 1; i <= GAP; ++i)
			if((line.find("i") != np) && (line.find("j") != np) && (line.find("k" + to_string(i)) != np) && (line.find("k" + to_string(GAP - 1)) != np) && (line.find("k" + to_string(i + 1))))
				(*this)[stoi(line.substr(line.find("i"), line.find("j")))][stoi(line.substr(line.find("j"), line.find("k" + to_string(GAP - 1))))][i] = stof(line.substr(line.find("k" + to_string(i)), line.find("k" + to_string(i + 1))));
	}
}

void hard_container_class::upload()
{
	ofstream matrix(OUT_PATH + to_string(this->counter_of_linked_container_class) + ".txt");	//заменить это на std::filesystem

	matrix.clear();

	for(int i = 0; i < this->counter_of_tokenizer; ++i)
		for (int j = 0; j < this->counter_of_tokenizer; ++j) {
			matrix << "i" << i << "j" << j;
			for (int k = -GAP - 1; k <= GAP; ++k)
				matrix << "k" + to_string(k) << (*this)[i][j][k];
			matrix << "k" + to_string(GAP + 1);
			matrix << endl;
		}

	this->clear();
}

#include "sparce_container_class.h"

void sparce_container_class::give_space(unsigned short int counter_of_tokenizer, int k)
{
    //kostil'
}

void sparce_container_class::increment(int first_dimension, int second_dimension, int third_dimension)
{
    (*this)[first_dimension][second_dimension].increment(third_dimension);
}

my_double sparce_container_class::get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension)
{
    return (*this)[first_dimension][second_dimension][third_dimension];
}

super_container_class* sparce_container_class::pow_all(int stepen)
{
    super_container_class* cl_for_return = new sparce_container_class(counter_of_tokenizer, k, hard_container_class_, this->filename);
    cl_for_return->give_space(counter_of_tokenizer, k);

    for (int i = 0; i < counter_of_tokenizer; ++i)
        for (int j = 0; j < counter_of_tokenizer; ++j)
            (*cl_for_return)[i][j].pow_all(stepen);

    return cl_for_return;
}

super_container_class* sparce_container_class::sqrt_all()
{
    super_container_class* cl_for_return = new sparce_container_class(counter_of_tokenizer, k, hard_container_class_, this->filename);
    cl_for_return->give_space(counter_of_tokenizer, k);

    for (int i = 0; i < counter_of_tokenizer; ++i)
        for (int j = 0; j < counter_of_tokenizer; ++j)
            (*cl_for_return)[i][j].sqrt_all();

    return cl_for_return;
}

class_of_first_bracket* sparce_container_class::get_vector_of_length()  //kostil' todo
{
    return nullptr;
}

void sparce_container_class::clear()
{
    if (is_download_dataed) {
        for (int i = 0; this->counter_of_tokenizer > i; ++i)
            this->_class_of_first_bracket_for_sparce_container_class[i].clear();

        this->_class_of_first_bracket_for_sparce_container_class = NULL;

        this->swap_is_download_dataed();
    }
}

void sparce_container_class::download_data()
{
    if (!this->is_download_dataed) {
        this->give_space(this->counter_of_tokenizer, this->get_k());

        ifstream matrix(OUT_PATH + to_string(this->counter_of_linked_container_class) + ".txt");	//çàìåíèòü ýòî íà std::filesystem

        while (!matrix.eof()) {
            string line;
            auto np = line.npos;
            std::getline(matrix, line);
            for (int i = GAP - 1; i <= GAP; ++i)
                if ((line.find("i") != np) && (line.find("j") != np) && (line.find("k" + to_string(i)) != np) && (line.find("k" + to_string(GAP - 1)) != np) && (line.find("k" + to_string(i + 1))))
                    (*this)[stoi(line.substr(line.find("i"), line.find("j")))][stoi(line.substr(line.find("j"), line.find("k" + to_string(GAP - 1))))][i] = stof(line.substr(line.find("k" + to_string(i)), line.find("k" + to_string(i + 1))));
        }

        matrix.close();

        this->is_download_dataed = !this->is_download_dataed;
    }
}

void sparce_container_class::upload_data()
{
    if (this->is_download_dataed) {
        ofstream m(OUT_PATH + to_string(this->counter_of_linked_container_class) + ".txt", ios::trunc);
        m.close();

        ofstream matrix(OUT_PATH + to_string(this->counter_of_linked_container_class) + ".txt");	//çàìåíèòü ýòî íà std::filesystem

        for (int i = 0; i < this->counter_of_tokenizer; ++i)
            for (int j = 0; j < this->counter_of_tokenizer; ++j) {
                matrix << "i" << i << "j" << j;
                for (int k = -GAP - 1; k <= GAP; ++k)
                    matrix << "k" + to_string(k) << (*this)[i][j][k];
                matrix << "k" + to_string(GAP + 1);
                matrix << endl;
            }

        this->clear();
        matrix.close();

        this->is_download_dataed = !this->is_download_dataed;
    }
}

void sparce_container_class::swap_is_download_dataed()
{
    this->is_download_dataed = !this->is_download_dataed;
}

super_class_of_first_bracket& sparce_container_class::operator[](long int i)                //vazno!
{
    return this->_class_of_first_bracket_for_sparce_container_class[i];
}

super_container_class* sparce_container_class::operator+(super_container_class* summed_class)
{
    return nullptr;
}

super_container_class* sparce_container_class::operator-(super_container_class* summed_class)
{
    return nullptr;
}

void sparce_container_class::operator+=(super_container_class* summed_class)
{
}

super_container_class* sparce_container_class::operator-=(super_container_class* summed_class)
{
    return nullptr;
}

bool sparce_container_class::operator==(super_container_class* summed_class)
{
    return false;
}

super_container_class* sparce_container_class::operator*(my_double _koef)
{
    return nullptr;
}

super_container_class* sparce_container_class::operator/(my_double _koef)
{
    return nullptr;
}

super_container_class* sparce_container_class::operator/(super_container_class* dividor_class)
{
    return nullptr;
}

super_container_class* sparce_container_class::operator-(my_double _num)
{
    return nullptr;
}

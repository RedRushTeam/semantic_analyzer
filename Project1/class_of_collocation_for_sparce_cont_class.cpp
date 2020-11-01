#include "class_of_collocation_for_sparce_cont_class.h"

void class_of_collocation_for_sparce_cont_class::give_space(int k)
{
    //tut nichego ne delaetsa, eto zatichka
}

//возможно я неверно написал все действия, где используются внутренние квадратные скобки

void class_of_collocation_for_sparce_cont_class::increment(int third_demention)
{
    auto _it = this->_scary_map.find(make_pair(this->_first_bracket, make_pair(this->_second_bracket, third_demention)));
    if (_it != this->_scary_map.end()) {
        auto tmp_pair = make_pair(make_pair(this->_first_bracket, make_pair(this->_second_bracket, third_demention)), (*_it).second + 1);
        this->_scary_map.erase(_it);
        this->_scary_map.insert(tmp_pair);
    }
}

my_double class_of_collocation_for_sparce_cont_class::get_count_of_concret_collocation(int third_demention)
{
    return this->_scary_map[make_pair(this->_first_bracket, make_pair(this->_second_bracket, third_demention))];
}

void class_of_collocation_for_sparce_cont_class::pow_all(int stepen)
{
    for (int i = -GAP - 1; i <= GAP; ++i) {  //i + (GAP + 1)
        auto _it = this->_scary_map.find(make_pair(this->_first_bracket, make_pair(this->_second_bracket, i + (GAP + 1))));
        if (_it != this->_scary_map.end()) {
            auto tmp_pair = make_pair(make_pair(this->_first_bracket, make_pair(this->_second_bracket, i + (GAP + 1))), pow((*_it).second, stepen));
            this->_scary_map.erase(_it);
            this->_scary_map.insert(tmp_pair);
        }
    }
}

void class_of_collocation_for_sparce_cont_class::sqrt_all()
{
    for (int i = -GAP - 1; i <= GAP; ++i) {  //i + (GAP + 1)
        auto _it = this->_scary_map.find(make_pair(this->_first_bracket, make_pair(this->_second_bracket, i + (GAP + 1))));
        if (_it != this->_scary_map.end()) {
            auto tmp_pair = make_pair(make_pair(this->_first_bracket, make_pair(this->_second_bracket, i + (GAP + 1))), sqrt((*_it).second));
            this->_scary_map.erase(_it);
            this->_scary_map.insert(tmp_pair);
        }
    }
}

void class_of_collocation_for_sparce_cont_class::clear()
{
    for (int i = -GAP - 1; i <= GAP; ++i)   //i + (GAP + 1)
        this->_scary_map.erase(make_pair(this->_first_bracket, make_pair(this->_second_bracket, i + (GAP + 1))));
}

my_double& class_of_collocation_for_sparce_cont_class::operator[](long int i)
{
    if (this->_scary_map.find(make_pair(this->_first_bracket, make_pair(this->_second_bracket, i + (GAP + 1)))) != this->_scary_map.end())
        return this->_scary_map[make_pair(this->_first_bracket, make_pair(this->_second_bracket, i + (GAP + 1)))];
    else {
        this->_scary_map[make_pair(this->_first_bracket, make_pair(this->_second_bracket, i + (GAP + 1)))] = 0;
        return this->_scary_map[make_pair(this->_first_bracket, make_pair(this->_second_bracket, i + (GAP + 1)))];
    }
}

class_of_collocation class_of_collocation_for_sparce_cont_class::operator+(class_of_collocation summed_class)
{
    class_of_collocation cl_for_return(GAP);
    cl_for_return.give_space(GAP);
    for (int i = -GAP - 1; i <= GAP; ++i)
        cl_for_return[i] = (*this)[i] + summed_class[i];

    return cl_for_return;
}

class_of_collocation class_of_collocation_for_sparce_cont_class::operator-(class_of_collocation _class)
{
    class_of_collocation cl_for_return(GAP);
    cl_for_return.give_space(GAP);
    for (int i = -GAP - 1; i <= GAP; ++i)
        if ((*this)[i] - _class[i] >= 0)
            cl_for_return[i] = (*this)[i] - _class[i];
        else
            cl_for_return[i] = 0;

    return cl_for_return;
}

class_of_collocation class_of_collocation_for_sparce_cont_class::operator-=(class_of_collocation _class)    //TODO Fix this
{
    return class_of_collocation();
}

class_of_collocation class_of_collocation_for_sparce_cont_class::operator+=(class_of_collocation summed_class)    //TODO Fix this
{
    return class_of_collocation();
}

class_of_collocation class_of_collocation_for_sparce_cont_class::operator*(my_double _number)
{
    class_of_collocation cl_for_return(GAP);
    cl_for_return.give_space(GAP);
    for (int i = -GAP - 1; i <= GAP; ++i)
        cl_for_return[i] = (*this)[i] * _number;

    return cl_for_return;
}

class_of_collocation class_of_collocation_for_sparce_cont_class::operator/(my_double _number)
{
    class_of_collocation cl_for_return(GAP);
    cl_for_return.give_space(GAP);
    for (int i = -GAP - 1; i <= GAP; ++i) {
        cl_for_return[i] = (*this)[i] / _number;
    }

    return cl_for_return;
}

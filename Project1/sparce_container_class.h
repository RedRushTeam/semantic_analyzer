#pragma once
#include "hard_container_class.h"

class sparce_container_class :
    public super_container_class
{
    sparce_container_class() {
        ++counter_of_linked_container_class;
        this->_class_of_first_bracket_for_sparce_container_class = new class_of_first_bracket_for_sparce_container_class();
    }

    sparce_container_class(unsigned short int counter_of_tokenizer, char k, type_of_cont_class _type_of_cont_class, fs::path filename) :
        super_container_class(counter_of_tokenizer, k, _type_of_cont_class, filename) {
        ++counter_of_linked_container_class;
        this->_class_of_first_bracket_for_sparce_container_class = new class_of_first_bracket_for_sparce_container_class();
    }

    sparce_container_class(char k, type_of_cont_class _type_of_cont_class, fs::path filename) :
        super_container_class(k, _type_of_cont_class, filename) {
        ++counter_of_linked_container_class;
        this->_class_of_first_bracket_for_sparce_container_class = new class_of_first_bracket_for_sparce_container_class();
    }

    // Унаследовано через super_container_class
    //methods
    virtual void give_space(unsigned short int counter_of_tokenizer, int k) override;
    virtual void increment(int first_dimension, int second_dimension, int third_dimension) override;
    virtual my_double get_count_of_concret_collocation(int first_dimension, int second_dimension, int third_dimension) override;
    virtual super_container_class* pow_all(int stepen) override;
    virtual super_container_class* sqrt_all() override;
    virtual class_of_first_bracket* get_vector_of_length() override;
    virtual void clear() override;
    virtual void download_data() override;
    virtual void upload_data() override;
    virtual void swap_is_download_dataed() override;

    //operators
    virtual super_class_of_first_bracket& operator[](long int i) override;
    virtual super_container_class* operator+(super_container_class* summed_class) override;
    virtual super_container_class* operator-(super_container_class* summed_class) override;
    virtual void operator+=(super_container_class* summed_class) override;
    virtual super_container_class* operator-=(super_container_class* summed_class) override;
    virtual bool operator==(super_container_class* summed_class) override;
    virtual super_container_class* operator*(my_double _koef) override;
    virtual super_container_class* operator/(my_double _koef) override;
    virtual super_container_class* operator/(super_container_class* dividor_class) override;
    virtual super_container_class* operator-(my_double _num) override;

private:
    class_of_first_bracket_for_sparce_container_class* _class_of_first_bracket_for_sparce_container_class;
};


#pragma once
#include "analyzer.h"

class Singleton
{
public:
	//method for use
	static Singleton& initialization();

	//public methods
	void push_container(container_class _container_class);
	list<container_class> get_list_of_container_class() const;
	void calculate_mat_ozidanie();
	void calculate_mat_disperse();
	void calculate_sredne_kv_otklonenie();
	void calculate_sredne_kv_otklonenie_fixed();
	void calculate_asymmetry_coefficient();
	void calculate_excess_ratio();
	void out_for_chart();

	//getters
	container_class get_sredne_kv_otklonenie() const;
	container_class get_sredne_kv_otklonenie_fixed() const;
	container_class get_mat_ozidanie() const;
	container_class get_mat_disperse() const;
	container_class get_asymmetry_coefficient() const;
	container_class get_excess_ratio() const;
	int get_length_of_all_container_class() const;
	container_class calculate_parametr_to_one_term(container_class _parametr);

	//bool remove_container_class(container_class _container_class);	//fix this!
private:
	//private methods
	my_double divider(int size);
	container_class calculate_sample_mean();

	//private elems
	container_class excess_ratio;
	container_class asymmetry_coefficient;
	container_class sredne_kv_otklonenie_fixed;
	container_class sredne_kv_otklonenie;
	container_class mat_disperse;
	container_class mat_ozidanie;
	list<container_class> list_of_container_class;

	//private methods for create
	Singleton() {}
	Singleton(const Singleton& orig) {}
	Singleton operator = (const Singleton& orig) { return *this; }
	virtual ~Singleton() {}
};


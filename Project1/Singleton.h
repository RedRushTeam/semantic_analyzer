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

	//getters
	my_double get_sredne_kv_otklonenie() const;
	my_double get_sredne_kv_otklonenie_fixed() const;
	my_double get_mat_ozidanie() const;
	my_double get_mat_disperse() const;
	my_double get_asymmetry_coefficient() const;
	my_double get_excess_ratio() const;
	int get_length_of_all_container_class() const;

	//bool remove_container_class(container_class _container_class);	//fix this!
private:
	//private methods
	my_double divider(int size);
	my_double calculate_sample_mean();

	//private elems
	my_double excess_ratio;
	my_double asymmetry_coefficient;
	my_double sredne_kv_otklonenie_fixed;
	my_double sredne_kv_otklonenie;
	container_class _container_class;
	my_double mat_disperse;
	my_double mat_ozidanie;
	list<container_class> list_of_container_class;

	//private methods for create
	Singleton() {}
	Singleton(const Singleton& orig) {}
	Singleton operator = (const Singleton& orig) { return *this; }
	virtual ~Singleton() {}
};


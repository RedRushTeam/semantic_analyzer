#pragma once
#include "analyzer.h"

class Singleton
{
public:
	static Singleton& initialization();

	void push_container(container_class _container_class);
	list<container_class> get_list_of_container_class() const;
	void calculate_mat_ozidanie();
	void calculate_mat_disperse();
	void calculate_sredne_kv_otklonenie();
	void calculate_sredne_kv_otklonenie_fixed();
	my_double get_sredne_kv_otklonenie() const;
	my_double get_sredne_kv_otklonenie_fixed() const;
	my_double get_mat_ozidanie() const;

	//bool remove_container_class(container_class _container_class);
private:
	my_double divider(int size);

	my_double sredne_kv_otklonenie_fixed;
	my_double sredne_kv_otklonenie;
	container_class _container_class;
	my_double mat_disperse;
	my_double mat_ozidanie;
	list<container_class> list_of_container_class;

	Singleton() {}
	Singleton(const Singleton& orig) {}
	Singleton operator = (const Singleton& orig) { return *this; }
	virtual ~Singleton() {}
};


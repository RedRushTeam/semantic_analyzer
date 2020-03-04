#pragma once
#include "analyzer.h"

class Singleton
{
public:
	//method for use
	static Singleton& initialization();

	//public methods
	void push_container(container_class_ _hard_container_class);
	list<container_class_> get_list_of_hard_container_class() const;
	void calculate_sample_mean();
	void calculate_mat_ozidanie();
	void calculate_mat_disperse();
	void calculate_sredne_kv_otklonenie();
	void calculate_sredne_kv_otklonenie_fixed();
	void calculate_asymmetry_coefficient();
	void calculate_excess_ratio();
	void calculate_params_for_charts();
	void out_for_chart();
	void sinchronize_terms();
	void give_space();
	void find_fluctuations();
	void clear(type_of_purpose_of_cont_class _type_of_cont_class);

	//getters
	container_class_ get_sredne_kv_otklonenie() const;
	container_class_ get_sredne_kv_otklonenie_fixed() const;
	container_class_ get_mat_ozidanie() const;
	container_class_ get_mat_disperse() const;
	container_class_ get_asymmetry_coefficient() const;
	container_class_ get_excess_ratio() const;
	container_class_ get_sample_mean_all() const;
	int get_length_of_all_hard_container_class() const;
	container_class_ calculate_parametr_to_one_term(container_class_ _parametr);

	bool remove_hard_container_class(container_class_ _hard_container_class);	//fix this!
private:
	//private methods
	my_double divider(int size);

	//private elems
	container_class_ sample_mean_all;
	container_class_ excess_ratio;
	container_class_ asymmetry_coefficient;
	container_class_ sredne_kv_otklonenie_fixed;
	container_class_ sredne_kv_otklonenie;
	container_class_ mat_disperse;
	container_class_ mat_ozidanie;
	list<container_class_> list_of_hard_container_class;
	container_class_ sum;
	container_class_ razn;
	container_class_ shhh; //shhh = this->calculate_parametr_to_one_term(this->mat_ozidanie);
	container_class_ chart;


	//private methods for create
	Singleton() {}
	Singleton(const Singleton& orig) {}
	Singleton operator = (const Singleton& orig) { return *this; }
	virtual ~Singleton() {}
};


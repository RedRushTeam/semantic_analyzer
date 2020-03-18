#pragma once
#include "analyzer.h"

class Singleton
{
public:
	//method for use
	static Singleton& initialization();

	//public methods
	void push_container(container_class_interface* _hard_container_class);
	vector<container_class_interface*> get_vec_of_container_class_interface() const;
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
	void sinchronize_terms(container_class_interface* _container_class);
	void find_fluctuations();
	void clear(type_of_purpose_of_cont_class _type_of_cont_class);
	void prepare_data_with_link_for_text(fs::path filename);
	void set_parser(parser* _parser);
	void set_analyzer(analyzer* _analyzer);
	void set_hEngine(HLEM& hEngine);
	void prepare_data_in_container_class(container_class_interface* _container_class_interface);

	//getters
	container_class_interface* get_sredne_kv_otklonenie() const;
	container_class_interface* get_sredne_kv_otklonenie_fixed() const;
	container_class_interface* get_mat_ozidanie() const;
	container_class_interface* get_mat_disperse() const;
	container_class_interface* get_asymmetry_coefficient() const;
	container_class_interface* get_excess_ratio() const;
	container_class_interface* get_sample_mean_all() const;
	int get_length_of_all_hard_container_class() const;
	container_class_interface* calculate_parametr_to_one_term(container_class_interface* _parametr);

	bool remove_hard_container_class(container_class_interface* _hard_container_class);	//fix this!

private:
	//private methods
	my_double divider(int size);

	//private elems
	container_class_interface* sample_mean_all;
	container_class_interface* excess_ratio;
	container_class_interface* asymmetry_coefficient;
	container_class_interface* sredne_kv_otklonenie_fixed;
	container_class_interface* sredne_kv_otklonenie;
	container_class_interface* mat_disperse;
	container_class_interface* mat_ozidanie;
	vector<container_class_interface*> vec_of_container_class_interface;
	container_class_interface* sum;
	container_class_interface* razn;
	container_class_interface* shhh;
	container_class_interface* chart;
	parser* _parser;
	analyzer* _analyzer;
	HLEM hEngine;
	unsigned int max_cont_size = 0;


	//private methods for create
	Singleton() {}
	Singleton(const Singleton& orig) {}
	Singleton operator = (const Singleton& orig) { return *this; }
	virtual ~Singleton() {}
};


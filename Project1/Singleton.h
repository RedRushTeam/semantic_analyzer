#pragma once
#include "analyzer.h"

class Singleton
{
public:
	//method for use
	static Singleton& initialization();

	//public methods
	void create_attributes(int vec_size);
	void push_container(super_container_class* _hard_container_class);
	vector<super_container_class*> get_vec_of_hard_container_class() const;
	void calculate_max_cont_size();
	void calculate_sample_mean();
	void calculate_mat_ozidanie();
	void calculate_mat_disperse();
	void calculate_sredne_kv_otklonenie();
	void calculate_sredne_kv_otklonenie_fixed();
	void calculate_asymmetry_coefficient();
	void calculate_excess_ratio();
	void out_for_chart();
	void sinchronize_terms();
	void sinchronize_terms(super_container_class& _container_class);
	void find_fluctuations();
	void clear(type_of_purpose_of_cont_class _type_of_cont_class);
	void prepare_data_with_link_for_text(fs::path filename);
	void set_parser(parser* _parser);
	void set_analyzer(analyzer* _analyzer);
	void set_hEngine(HLEM& hEngine);
	void prepare_data_in_container_class(int _super_container_class_number);

	//getters
	super_container_class* get_sredne_kv_otklonenie() const;
	super_container_class* get_sredne_kv_otklonenie_fixed() const;
	super_container_class* get_mat_ozidanie() const;
	super_container_class* get_mat_disperse() const;
	super_container_class* get_asymmetry_coefficient() const;
	super_container_class* get_excess_ratio() const;
	super_container_class* get_sample_mean_all() const;
	int get_length_of_all_hard_container_class() const;
	super_container_class* calculate_parametr_to_one_term(super_container_class* _parametr);

	bool remove_hard_container_class(super_container_class* _hard_container_class);	//fix this!

private:
	//private methods
	my_double divider(int size);

	//private elems
	super_container_class* sample_mean_all;
	super_container_class* excess_ratio;
	super_container_class* asymmetry_coefficient;
	super_container_class* sredne_kv_otklonenie_fixed;
	super_container_class* sredne_kv_otklonenie;
	super_container_class* mat_disperse;
	super_container_class* mat_ozidanie;
	vector<super_container_class*> vec_of_hard_container_class;
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


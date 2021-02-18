#pragma once
#include "analyzer.h"

class Singleton
{
public:
	//method for use
	static Singleton& initialization();

	//public methods
	void push_container(hard_container_class _hard_container_class);
	vector<hard_container_class> get_vec_of_hard_container_class() const;
	//SVD methods
	void calculate_SVD_matrix();
	VectorXf calculate_Singular_Value();
	MatrixXf get_singular_V_matrix();
	MatrixXf get_singular_U_matrix();
	//

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
	void sinchronize_terms(hard_container_class _container_class);
	void find_fluctuations();
	void clear(type_of_purpose_of_cont_class _type_of_cont_class);
	void prepare_data_with_link_for_text(fs::path filename);
	void set_parser(parser* _parser);
	void set_analyzer(analyzer* _analyzer);
	void set_hEngine(HLEM& hEngine);
	void prepare_data_in_container_class(int _hard_container_class_number);

	//getters
	hard_container_class get_sredne_kv_otklonenie() const;
	hard_container_class get_sredne_kv_otklonenie_fixed() const;
	hard_container_class get_mat_ozidanie() const;
	hard_container_class get_mat_disperse() const;
	hard_container_class get_asymmetry_coefficient() const;
	hard_container_class get_excess_ratio() const;
	hard_container_class get_sample_mean_all() const;
	int get_length_of_all_hard_container_class() const;
	hard_container_class calculate_parametr_to_one_term(hard_container_class _parametr);

	bool remove_hard_container_class(hard_container_class _hard_container_class);	//fix this!

private:
	//private methods
	my_double divider(int size);

	//private elems for SVD
	MatrixXf* m;
	JacobiSVD<MatrixXf>* Jacobi_svd = nullptr;	//SVD for small matrix
	BDCSVD<MatrixXf>* BDCSVD_svd = nullptr;		//SVD for big matrix

	//private elems
	hard_container_class sample_mean_all;
	hard_container_class excess_ratio;
	hard_container_class asymmetry_coefficient;
	hard_container_class sredne_kv_otklonenie_fixed;
	hard_container_class sredne_kv_otklonenie;
	hard_container_class mat_disperse;
	hard_container_class mat_ozidanie;
	vector<hard_container_class> vec_of_hard_container_class;
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


#pragma once
#include "analyzer.h"

class Singleton
{
public:
	static Singleton& initialization();

	void push_container(container_class _container_class);
	list<container_class> get_list_of_container_class() const;
	//bool remove_container_class(container_class _container_class);

private:
	container_class _container_class;

	list<container_class> list_of_container_class;

	Singleton() {}
	Singleton(const Singleton& orig) {}
	Singleton operator = (const Singleton& orig) { return *this; }
	virtual ~Singleton() {}
};


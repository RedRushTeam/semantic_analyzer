#pragma once
#include "analyzer.h"

class Singleton
{
public:
	static Singleton& initialization();

	container_class get_container_class() const;
	void set_container_class(container_class _container_class);
private:
	container_class _container_class;


	Singleton() {}
	Singleton(const Singleton& orig) {}
	Singleton operator = (const Singleton& orig) { return *this; }
	virtual ~Singleton() {}
};


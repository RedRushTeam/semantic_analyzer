#include "Singleton.h"

Singleton& Singleton::initialization()
{
	static Singleton _singleton;
	return _singleton;
}

container_class Singleton::get_container_class() const
{
	return _container_class;
}

void Singleton::set_container_class(container_class _container_class)
{
	this->_container_class = _container_class;
}

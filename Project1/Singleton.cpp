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

void Singleton::push_container(container_class* _container_class)
{
	this->list_of_container_class.push_back(_container_class);
}

list<container_class*> Singleton::get_list_of_container_class() const
{
	return this->list_of_container_class;
}

bool Singleton::remove_container_class(container_class* _container_class)
{
	auto tmp = find(this->list_of_container_class.begin(), this->list_of_container_class.end(), _container_class);
	if (tmp == this->list_of_container_class.end())
		return false;
	this->list_of_container_class.erase(tmp);
}

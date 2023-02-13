#include "Serialization.hpp"
#include "Data.hpp"

Data::Data() : _name("") {}

Data::Data(const Data &src) { *this = src; }

Data::~Data() {}

Data &Data::operator=(Data const &rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

std::string Data::getName()
{
	return _name;
}

std::string Data::setName(std::string name)
{
	return _name = name;
}
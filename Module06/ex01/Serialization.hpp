#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include "Data.hpp"

class Serialization
{
private:

public:
	Serialization();
	Serialization(Serialization const &src);
	~Serialization();
	Serialization &operator=(Serialization const &rhs);

	uintptr_t serialize(Data *ptr);
	Data *deserialize(uintptr_t raw);
};

#endif

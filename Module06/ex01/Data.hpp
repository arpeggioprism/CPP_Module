#ifndef DATA_HPP
#define DATA_HPP

#include "Serialization.hpp"

struct Data
{
private:
	std::string _name;

public:
	Data();
	Data(Data const &src);
	~Data();
	Data &operator=(Data const &rhs);

	std::string getName();
	std::string setName(std::string name);
};

#endif
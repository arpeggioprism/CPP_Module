#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:

public:
	Dog();
	~Dog();
	Dog(Dog const &src);

	Dog &operator=(Dog const &rhs);

	void makeSound() const;
};

#endif

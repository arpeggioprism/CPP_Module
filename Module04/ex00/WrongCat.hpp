#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
	WrongCat(WrongCat const &src);
	~WrongCat();

	WrongCat &operator=(WrongCat const &rhs);

	void makeSound() const;
};

#endif

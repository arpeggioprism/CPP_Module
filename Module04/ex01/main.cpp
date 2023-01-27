#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	std::cout << "\n\n----------test1----------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << "\n\n----------test2----------" << std::endl;
	Animal *animal[4] = {new Dog(), new Cat(), new Dog(), new Cat()};

	for (int i = 0; i < 4; i++)
		animal[i]->makeSound();
	for (int i = 0; i < 4; i++)
		delete animal[i];

	std::cout << "\n\n----------test3----------" << std::endl;
	Dog dog2;
	{
		Dog dog3 = dog2;
		dog3.makeSound();
	}
	std::cout << std::endl;

	system("leaks a.out");
}
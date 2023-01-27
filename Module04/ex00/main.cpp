#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "\n--------Animal Test--------" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete i;
    delete j;

    std::cout << "\n--------Wrong Animal Test--------" << std::endl;
    const WrongAnimal *k = new WrongCat();

    std::cout << k->getType() << " " << std::endl;
    k->makeSound();

    delete k;

    system("leaks a.out");

    return (0);
}
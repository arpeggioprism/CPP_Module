#include "Zombie.hpp"

int main(void)
{
	Zombie	*heapZombie = newZombie("Foo");

	heapZombie->announce();
	delete heapZombie;
	randomChump("Stack Zombie");
	return 0;
}
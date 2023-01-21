#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap harry("harry");
    ClapTrap voldemort("voldemort");
    ClapTrap hermione("hermione");
    ClapTrap bellatrix("bellatrix");

    std::cout << "\n\n-------------- attack test --------------" << std::endl;
    for (int i = 0; i < 10; i++)
        harry.attack("voldemort");
    harry.attack("voldemort");
    harry.beRepaired(10);

    std::cout << "\n\n------------ takeDamage test ------------" << std::endl;
    voldemort.takeDamage(10);
    voldemort.attack("hermione");
    voldemort.beRepaired(10);

    std::cout << "\n\n-------------- repair test --------------" << std::endl;
    bellatrix.takeDamage(9);
    bellatrix.beRepaired(1);
    bellatrix.takeDamage(10);
    bellatrix.takeDamage(1);

    std::cout << std::endl;

    return 0;
}
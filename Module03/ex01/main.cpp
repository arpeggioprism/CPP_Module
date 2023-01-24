#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap harry("harry");
    ScavTrap voldemort("voldemort");

    std::cout << "\n\n------------ guardGate test ------------" << std::endl;
    harry.guardGate();

    std::cout << "\n\n------------ attack test ---------------" << std::endl;
    harry.attack("voldemort");
    voldemort.takeDamage(20);
    std::cout << std::endl;
}

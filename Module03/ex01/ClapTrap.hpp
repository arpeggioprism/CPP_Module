#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &src);
    virtual ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &rhs);

    virtual void attack(const std::string &target) = 0;
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif

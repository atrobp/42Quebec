#pragma once

#include <iostream>

class ClapTrap {
private:
    std::string _name;
    int _hitPoints;
    int _attackDamage;
    int _energyPoints;

public:
    ClapTrap(std::string name);
    ~ClapTrap();

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

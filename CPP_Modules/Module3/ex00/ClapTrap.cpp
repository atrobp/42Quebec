#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << _name
              << " has spawned!"
              << " (Constructor called)"
              << std::endl;
}
ClapTrap::~ClapTrap() {
    std::cout << "Destructor called"
              << std::endl;
}

void    ClapTrap::attack(const std::string &target) {
    std::cout << "ClapTrap "
              << _name;
    if (_energyPoints > 0) {
        std::cout << " attacks " << target + ","
                  << " causing " << _attackDamage << " points of damage";
        _energyPoints -= 1;
    } else {
        std::cout << " has no more energy!";
    }
    std::cout << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    std::cout << _name;
    if (_hitPoints <= 0){
        std::cout << " is alread dead!";
    } else {
        std::cout << " has taken " << amount << " of damage! ";
        _hitPoints -= amount;
    }
    std::cout << std::endl;
}
void    ClapTrap::beRepaired(unsigned int amount) {
    std::cout << _name
              << " is reparing...  ";
    if (amount > 10) {
        std::cout << "max hitpoints repaired!";
    } else {
        std::cout << "for " << amount;
    }
    std::cout << std::endl;
}

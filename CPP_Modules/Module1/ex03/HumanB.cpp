#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon *weapon) : _name(name), _weapon(weapon) {
    std::cout << _name
              << ": is ready for battle."
              << std::endl;
}

HumanB::HumanB(std::string name) : _name(name) {
    std::cout << _name
              << ": is somewhat ready for battle."
              << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}

void    HumanB::attack() {
    std::cout << _name
              << " attacks with their "
              << _weapon->getType()
              << std::endl;
}


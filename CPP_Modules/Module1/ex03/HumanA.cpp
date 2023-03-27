#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
    std::cout << _name
              << ": is ready for battle."
              << std::endl;
}

void    HumanA::attack() {
    std::cout << _name
              << " attacks with their "
              << _weapon.getType()
              << std::endl;
}

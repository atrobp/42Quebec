#include "Zombie.hpp"

void Zombie::_announce() {
    std::cout << _name
              << ": BraiiiiiiinnnzzzZ..."
              << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
    _announce();
}

Zombie::~Zombie() {
    std::cout << _name
              << " is no more (destroyed)"
              << std::endl;
}

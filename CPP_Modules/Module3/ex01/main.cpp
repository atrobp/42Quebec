#include "ClapTrap.hpp"

int main()
{
    ClapTrap mario("Mario");

    mario.attack("Luigi");
    mario.takeDamage(4);
    mario.beRepaired(31);
    mario.takeDamage(11);
    return 0;
}


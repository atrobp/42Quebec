#include "Zombie.hpp"

int main() {
    Zombie *uniqueZombie = newZombie("Dracula");

    randomChump("Mario");
    delete uniqueZombie;
}

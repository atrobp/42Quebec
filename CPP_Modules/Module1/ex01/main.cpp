#include "Zombie.hpp"

int main() {
    unsigned int num = 3;

    Zombie *zhorde = zombieHorde(num, "wario");

    delete [] zhorde;
    return 0;
}

#pragma once

#include <iostream>

class Zombie {
private:
    std::string _name;
    void _announce( void );

public:
    Zombie( std::string name );
    ~Zombie( void );
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

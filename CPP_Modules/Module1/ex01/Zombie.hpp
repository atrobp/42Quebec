#pragma once

#include <iostream>

class Zombie {
private:
    std::string _name;

public:
    Zombie( void );
    Zombie( std::string name );
    ~Zombie( void );

    void _announce( void );
    void    setName(std::string name) {
        _name = name;
    }
};

Zombie* zombieHorde( int N, std::string name );

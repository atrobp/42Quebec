#pragma once

#include <iostream>

class Weapon {
private:
    std::string _type;

public:
    Weapon(std::string weapon);

    std::string& getType() {
        return _type;
    }
    void    setType(std::string newtype) {
        _type = newtype;
    }
};

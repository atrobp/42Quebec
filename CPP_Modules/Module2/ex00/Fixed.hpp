#pragma once

#include <iostream>

class Fixed {
private:
    int              _fixedPoint;
    static const int _bits = 8;

public:
    Fixed();
    Fixed(Fixed &fixed);
    Fixed& operator=(Fixed &fixed);
    ~Fixed();

    int  getRawBits() const;
    void setRawBits(int const raw);
};

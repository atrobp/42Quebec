#include "Fixed.hpp"


Fixed::Fixed(){
    std::cout << "Default constructor called"
              << std::endl;
    setRawBits(0);
}

Fixed::Fixed(const int num){
    std::cout << "Int constructor called"
              << std::endl;
    setRawBits(0);
}

Fixed::Fixed(const float num){
    std::cout << "Float constructor called"
              << std::endl;
    setRawBits(0);
}

Fixed::Fixed(Fixed &fixed) {
    std::cout << "Copy constructor called"
              << std::endl;
    setRawBits(0);
}

Fixed& Fixed::operator=(Fixed &fixed) {
    std::cout << "Copy assignment operator called "
              << std::endl;
    setRawBits(0);
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called"
              << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits "
              << "member function called"
              << std::endl;
    return _fixedPoint;
}

void   Fixed::setRawBits(int const raw) {
    _fixedPoint = raw;
}

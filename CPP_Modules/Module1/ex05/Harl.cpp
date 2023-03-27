#include "Harl.hpp"

Harl::Harl() {
    std::cout << "Harl has awaken "
              << "*FLOOR IS SHAKING*"
              << std::endl;
}

void    Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*ptr[i])();
            std::cout << std::endl;
            return;
        }
    }
}

void    Harl::_debug() {
    std::cout << "I love having extra bacon "
              << "for my 7XL-double-cheese-triple-pickle-specialketchup "
              << "burger. I really do!";
}

void    Harl::_info() {
    std::cout << "I cannot believe adding extra bacon costs more money. "
              << "You didn't put enough bacon in my burger! If you did, "
              << "I wouldn't be asking for more!";
}

void    Harl::_warning() {
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I've been coming for years whereas you started working "
              << "here since last month.!";
}

void    Harl::_error() {
    std::cout << "This is unacceptable! I want to speak to the manager now.";
}

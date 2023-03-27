#include "Harl.hpp"

void    Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptr[4])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            std::cout << "[ " << level << " ]"
                      << std::endl;
            for (int j = i; j < 4; j++)
            {
                (this->*ptr[j])();
                std::cout << std::endl;
            }
            return;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]";
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

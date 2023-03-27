#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout.width(29);
    std::cout << std::left << "Address of str: "              << std::right << &str       << std::endl;
    std::cout.width(29);
    std::cout << std::left << "Address of pointer to str: "   << std::right << &stringPTR << std::endl;
    std::cout << std::left << "Address of reference to str: " << std::right << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout.width(29);
    std::cout << std::left << "value of str: "              << std::right << str        << std::endl;
    std::cout.width(29);
    std::cout << std::left << "value of pointer to str: "   << std::right << *stringPTR << std::endl;
    std::cout.width(29);
    std::cout << std::left << "value of reference to str: " << std::right << stringREF  << std::endl;

}

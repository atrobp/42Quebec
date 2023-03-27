#include "Harl.hpp"

int main(int argc, char const *argv[]) {
    Harl        karenfilter;

    switch (argc) {
        case 2: {
            karenfilter.complain(argv[1]);
            std::cout << std::endl;
            break;
        }
        default: {
            std::cout << " [ PIECE OF MIND ????? NEVER]";
            break;
        }
    }
    std::cout << std::endl;
    return 0;
}

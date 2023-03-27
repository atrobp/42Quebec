#include "main.hpp"

int main(int argc, char *argv[])
{
    std::string     lines;
    std::ifstream   file;
    std::string     temp = argv[1];
    std::ofstream   outfile("hello.replace");

    switch (argc) {
        case 4: {
            file.open(argv[1]);
            if (file.is_open()) {
                while (getline(file, lines)) {
                    outfile << find_replace(lines, argv[2], argv[3]);
                }
            } else {
                std::cout << "Coudn't open the file";
            }
            break;
        }
        default: {
            std::cout << "Invalid # of arguments!";
            break;
        }
    }
    return 0;
}

std::string find_replace(std::string lines, std::string s1, std::string s2) {
    int j = 0;

    for (int i = 0; lines[i]; i++) {
        j = 0;
        while (s1[j] == lines[i + j]) {
            j += 1;
        }
        if (s1[j] == '\0') {
            while (j > 0) {
                j--;
            }
            while (s2[j]) {
                lines[i + j] = s2[j];
                j += 1;
            }
        }
    }
    return lines;
}

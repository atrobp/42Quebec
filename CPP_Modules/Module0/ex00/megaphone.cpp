#include <iostream>

int main(int ac, char **av) {
	switch (ac) {
	case 1:
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		break;
	default:
		for (int i = 1; i < ac; i += 1) {
			for (int j = 0; av[i][j]; j += 1) {
				std::cout << (char)toupper(av[i][j]);
			}
			std::cout << " ";
		}
		break;
	}
	std::cout << std::endl;
	return 0;
}

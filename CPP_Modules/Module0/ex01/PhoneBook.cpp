#include "PhoneBook.hpp"



int	main() {
	PhoneBook phoneBook;
	std::string command;

	while (1) {
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "EXIT") {
			break;
		} else if (command == "ADD") {
			//add function
		} else if (command == "SEARCH") {
			//search function
		} else {
			std::cout << "Invalid command!" << std::endl;
		}
	}
	std::cout << "Bye!" << std::endl;
	return 0;
}

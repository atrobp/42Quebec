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
			phoneBook.addContact();
		} else if (command == "SEARCH") {
			phoneBook.searchContact();
		} else {
			std::cout << "Invalid command!" << std::endl;
		}
	}
	std::cout << "Bye!" << std::endl;
	return 0;
}

void	PhoneBook::addContact() {
	std::string str[5] = {"first name", "last name", "nickname", "phonenumber", "darkest secret"};
	for (int i = 0; i < 5; i++){
		std::cout << "Enter " << str[i] << ": ";
		std::getline(std::cin, _info);
		while (_info.length() == 0) {
			std::getline(std::cin, _info);
		}
	}
	// std::cout << "Enter first name: ";
	// std::getline(std::cin, _firstName);
}

void	PhoneBook::searchContact() {

}

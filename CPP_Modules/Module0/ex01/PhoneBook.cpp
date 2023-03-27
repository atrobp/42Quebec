#include "PhoneBook.hpp"

enum Commands {
	ADD,
	EXIT,
	SEARCH,
	INVALID
};

Commands GetCommand(std::string input) {
	if (input == "EXIT") return EXIT;
	else if (input == "ADD") return ADD;
	else if (input == "SEARCH") return SEARCH;
	else return INVALID;
}

int	main() {
	PhoneBook phone_book;
	std::string command;

	while (1) {
		std::cout << "Enter command: ";
		std::getline(std::cin, command);

		switch (GetCommand(command)) {
			case ADD: {
				phone_book.addContact();
				break ;
			}
			case EXIT: {
				std::cout << "Cya never!" << std::endl;
				return 0;
			}
			case SEARCH: {
				phone_book.searchContact();
				break;
			}
			default: {
				break;
			}
		}
	}
	return 0;
}

PhoneBook::PhoneBook() {
	this->index = 0;
	std::cout << "Hello and welcome to your "
				 "very first Phonebook!" << std::endl;
}

void	PhoneBook::addContact() {
	std::string str[5] = {"First name", "Last name", "Nick name", "Phone umber", "Darkest secret"};

	if (index >= 8) index = 7;

	for (int i = 0; i < 5; i++){
		std::cout << "Enter " << str[i] << ": ";
		std::getline(std::cin, contacts[index][i]);
		while (contacts[index][i].length() == 0) {
			std::getline(std::cin, contacts[index][i]);
		}
	}
	index += 1;
}

std::string	FixString(std::string str) {
	if (str.size() > 10) {
		str.resize(10);
		str[str.size() - 1] = '.';
	}
	return str;
}

void	PhoneBook::searchContact() {
	std::string str[5] = {"First name", "Last name", "Nick name", "Phone umber", "Darkest secret"};
	int 		num;

	if (index != 0) {
		std::cout << " ___________________________________________ " << std::endl;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << "Index";
		std::cout << "|" << std::setfill(' ') << std::setw(10) << "First name";
		std::cout << "|" << std::setfill(' ') << std::setw(10) << "Last name";
		std::cout << "|" << std::setfill(' ') << std::setw(10) << "Nick name";
		std::cout << "|" << std::endl;
		std::cout << "|__________|__________|__________|__________|" << std::endl;
		for (int i = 0; i < index; i++) {
			std::cout << "|" << std::setfill(' ') << std::setw(10) << i;
			std::cout << "|" << std::setfill(' ') << std::setw(10) << FixString(contacts[i][0]);
			std::cout << "|" << std::setfill(' ') << std::setw(10) << FixString(contacts[i][1]);
			std::cout << "|" << std::setfill(' ') << std::setw(10) << FixString(contacts[i][2]);
			std::cout << "|" << std::endl;
		}
		std::cout << "|-------------------------------------------|" << std::endl;
		std::cout << "Enter desired contact index number: ";
		std::getline(std::cin, choice);
		num = choice[0] - 48;
		if (choice.size() == 1 && num >= 0 && num < index) {
			for (int i = 0; i < 5; i++) {
				std::cout.width(15);
				std::cout << std::left << str[i] << std::right << " : ";
				std::cout << contacts[num][i] << std::endl;
			}
		} else std::cout << "Impossible to get contact info" << std::endl;
	}
}

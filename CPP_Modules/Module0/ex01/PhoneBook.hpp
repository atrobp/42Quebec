#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook {
	public:
		PhoneBook();
		void 	addContact();
		void	searchContact();
	private:
		int 		index;
		std::string choice;
		std::string	contacts[8][5];
};

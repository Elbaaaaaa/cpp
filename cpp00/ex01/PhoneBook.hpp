#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>

// colors

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		void	addContact(Contact contact);
		void	searchContact();
		void	displayContact(int index);
		std::string formatField(std::string str);
		PhoneBook();
		~PhoneBook();
};

#endif

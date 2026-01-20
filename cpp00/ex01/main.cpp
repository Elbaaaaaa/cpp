/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:39:08 by ebella            #+#    #+#             */
/*   Updated: 2025/08/25 14:47:42 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::string line;
	PhoneBook phoneBook;
	Contact contact;

	while(1)
	{
		std::cout << "PhoneBook: ";
		std::getline(std::cin, line);
		if (std::cin.eof())
			return (1);
		if (line == "ADD")
			phoneBook.addContact(contact);
		else if (line == "SEARCH")
			phoneBook.searchContact();
		else if (line == "EXIT")
			break ;
		else
			std::cout << RED << "Invalid command" << RESET << std::endl;
	}
	return (0);
}

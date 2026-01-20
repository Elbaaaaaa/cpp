/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:30:24 by ebella            #+#    #+#             */
/*   Updated: 2025/08/25 16:57:30 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>
# include <cctype>
# include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::displayContact(int index)
{
	if (contacts[index].getFirstName() == "")
	{
		std::cout << RED << "No contact found at index " << index << std::endl;
		std::cout << RESET;
		return ;
	}
	std::cout << GREEN << "First Name: " << contacts[index].getFirstName() << std::endl;
	std::cout << GREEN << "Last Name: " << contacts[index].getLastName() << std::endl;
	std::cout << GREEN << "Nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << GREEN << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << GREEN << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	std::cout << RESET;
}

std::string PhoneBook::formatField(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::addContact(Contact contact)
{
	std::string line;
	static int j = 0;
	std::cout << YELLOW <<"Type your name: ";
	std::getline(std::cin, line);
	contact.setFirstName(line);
	std::cout << YELLOW << "Type your lastName: ";
	std::getline(std::cin, line);
	contact.setLastName(line);
	std::cout << YELLOW << "Type your nickName: ";
	std::getline(std::cin, line);
	contact.setNickname(line);
	std::cout << YELLOW << "Type your phoneNumber: ";
	std::getline(std::cin, line);
	contact.setPhoneNumber(line);
	std::cout << YELLOW << "Type your darkestSecret: ";
	std::getline(std::cin, line);
	std::cout << RESET;
	contact.setDarkestSecret(line);
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].getFirstName() == "")
		{
			contacts[i].setFirstName(contact.getFirstName());
			contacts[i].setLastName(contact.getLastName());
			contacts[i].setNickname(contact.getNickname());
			contacts[i].setPhoneNumber(contact.getPhoneNumber());
			contacts[i].setDarkestSecret(contact.getDarkestSecret());
			break ;
		}else if (i == 6 && contacts[7].getFirstName() != "")
		{
			contacts[j].setFirstName(contact.getFirstName());
			contacts[j].setLastName(contact.getLastName());
			contacts[j].setNickname(contact.getNickname());
			contacts[j].setPhoneNumber(contact.getPhoneNumber());
			contacts[j].setDarkestSecret(contact.getDarkestSecret());
			j++;
			break ;
		}
	}
}

void PhoneBook::searchContact()
{
	std::string line;

	std::cout << GREEN << "| firstName|  lastName|  nickName|     index|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << GREEN << "|" << std::setw(10) << formatField(contacts[i].getFirstName())
				  << "|" << std::setw(10) << formatField(contacts[i].getLastName())
				  << "|" << std::setw(10) << formatField(contacts[i].getNickname())
				  << "|" << std::setw(10) << i << "|" << std::endl;
		std::cout << RESET;
	}
	std::cout << YELLOW << "Type the index of the contact to display: " << RESET;
	std::getline(std::cin, line);
	if (std::cin.eof())
		return ;
	int index = line[0] - '0';
	if (index < 0 || index > 7 || line.length() != 1)
	{
		std::cout << RED << "Invalid index" << RESET << std::endl;
		return ;
	}
	displayContact(index);
}

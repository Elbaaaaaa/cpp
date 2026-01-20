/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:48:57 by ebella            #+#    #+#             */
/*   Updated: 2025/08/25 14:37:23 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string str)
{
	Contact::firstName = str;
}

void Contact::setLastName(std::string str)
{
	Contact::lastName = str;
}

void Contact::setNickname(std::string str)
{
	Contact::nickname = str;
}

void Contact::setPhoneNumber(std::string str)
{
	Contact::phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str)
{
	Contact::darkestSecret = str;
}
std::string Contact::getDarkestSecret()
{
	return darkestSecret;
}

std::string Contact::getFirstName()
{
	return firstName;
}

std::string Contact::getLastName()
{
	return lastName;
}

std::string Contact::getNickname()
{
	return nickname;
}

std::string Contact::getPhoneNumber()
{
	return phoneNumber;
}

Contact::Contact()
{}

Contact::~Contact()
{}

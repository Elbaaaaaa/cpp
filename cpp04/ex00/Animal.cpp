/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:31:51 by ebella            #+#    #+#             */
/*   Updated: 2025/11/22 14:12:49 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << GREEN << "Default Animal constructor called" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << RED << "Animal Destructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& Animal)
{
	std::cout << GREEN << "Copy Animal constructor called" << RESET << std::endl;
	this->type = Animal.type;
}

std::string Animal::getType() const
{
	return (this->type);
}
void	Animal::makeSound() const
{
	if (this->type == "Dog")
		std::cout << MAGENTA << "Wouaf !!!" << RESET << std::endl;
	else if (this->type == "Cat")
		std::cout << MAGENTA << "Miaou !!!" << RESET << std::endl;
}

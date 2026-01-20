/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:18:27 by ebella            #+#    #+#             */
/*   Updated: 2025/11/22 14:19:44 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "Default WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal Destructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& WrongAnimal)
{
	std::cout << GREEN << "Copy WrongAnimal constructor called" << RESET << std::endl;
	this->type = WrongAnimal.type;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
void	WrongAnimal::makeSound() const
{
	if (this->type == "Cat")
		std::cout << MAGENTA << "Wouaf !!!" << RESET << std::endl;
	else if (this->type == "Dog")
		std::cout << MAGENTA << "Miaou !!!" << RESET << std::endl;
}

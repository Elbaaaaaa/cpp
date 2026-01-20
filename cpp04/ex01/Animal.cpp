/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:31:51 by ebella            #+#    #+#             */
/*   Updated: 2025/11/22 16:34:19 by ebella           ###   ########.fr       */
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
	std::cout << BLUE << "Animal sound..." << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:40:38 by ebella            #+#    #+#             */
/*   Updated: 2025/11/22 16:35:53 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << GREEN << "Default Dog constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	if (this->brain)
		delete brain;
	std::cout << RED << "Dog Destructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& Dog)
{
	std::cout << GREEN << "Copy Dog constructor called" << RESET << std::endl;
	this->type = Dog.type;
	if (Dog.brain)
		this->brain = new Brain(*Dog.brain);
	else
		this->brain = NULL;
}

void Dog::setIdea(int index, const std::string& idea)
{
	if (this->brain)
		this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	if (this->brain)
		return this->brain->getIdea(index);
	return std::string();
}

void	Dog::makeSound() const
{
	std::cout << MAGENTA << "Wouaf !!!" << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:36:13 by ebella            #+#    #+#             */
/*   Updated: 2025/11/22 16:36:00 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << GREEN << "Default Cat constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	if (this->brain)
		delete brain;
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& Cat)
{
	std::cout << GREEN << "Copy Cat constructor called" << RESET << std::endl;
	this->type = Cat.type;
	if (Cat.brain)
		this->brain = new Brain(*Cat.brain);
	else
		this->brain = NULL;
}

void Cat::setIdea(int index, const std::string& idea)
{
	if (this->brain)
		this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	if (this->brain)
		return this->brain->getIdea(index);
	return std::string();
}

void	Cat::makeSound() const
{
	std::cout << MAGENTA << "Miaou !!!" << RESET << std::endl;
}

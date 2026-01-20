/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:40:38 by ebella            #+#    #+#             */
/*   Updated: 2025/11/22 14:12:09 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << GREEN << "Default Dog constructor called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "Dog Destructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& Dog)
{
	std::cout << GREEN << "Copy Dog constructor called" << RESET << std::endl;
	this->type = Dog.type;
}


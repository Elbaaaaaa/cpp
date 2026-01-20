/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:36:13 by ebella            #+#    #+#             */
/*   Updated: 2025/11/22 14:11:35 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << GREEN << "Default Cat constructor called" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << "Cat Destructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& Cat)
{
	std::cout << GREEN << "Copy Cat constructor called" << RESET << std::endl;
	this->type = Cat.type;
}

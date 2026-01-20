/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:16:30 by ebella            #+#    #+#             */
/*   Updated: 2025/11/22 14:30:28 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Cat";
	std::cout << GREEN << "Default WrongCat constructor called" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat Destructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& WrongCat)
{
	std::cout << GREEN << "Copy WrongCat constructor called" << RESET << std::endl;
	this->type = WrongCat.type;
}

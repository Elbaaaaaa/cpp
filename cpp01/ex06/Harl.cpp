/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:17:59 by ebella            #+#    #+#             */
/*   Updated: 2025/08/28 19:25:10 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << GREEN << "Harl was created." << RESET << std::endl;
}

Harl::~Harl()
{
	std::cout << RED << "Harl was destroyed" << RESET << std::endl;
}

void	Harl::debug()
{
	std::cout << GREEN << "DEBUG: "<< YELLOW << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << RESET << std::endl;
}

void	Harl::info()
{
	std::cout << BLUE << "INFO: " << YELLOW << "cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << RESET << std::endl;
}

void	Harl::warning()
{
	std::cout << ORANGE << "WARNING: " << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << RESET << std::endl;
}

void	Harl::error()
{
	std::cout << RED << "ERROR: " << YELLOW << "This is unacceptable! I want to speak to the manager now.\n" << RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	while (i < 4 && levels[i] != level)
		i++;
	
	switch (i)
	{
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
			break;
		default:
			std::cout << YELLOW << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

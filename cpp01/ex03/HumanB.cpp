/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 17:17:17 by ebella            #+#    #+#             */
/*   Updated: 2025/08/26 18:05:35 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	weapon = NULL;
	std::cout << GREEN << name << " was created with no weapon " << RESET << std::endl;
}

HumanB::HumanB(std::string name) : name(name)
{
	weapon = NULL;
	std::cout << GREEN << name << " was created with no weapon " << RESET << std::endl;
}

HumanB::~HumanB()
{
	std::cout << RED << name << " was destroyed" << RESET << std::endl;
}

void	HumanB::attack()
{
	if (weapon)
		std::cout << YELLOW << name << " attacks with their " << weapon->getType() << RESET << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

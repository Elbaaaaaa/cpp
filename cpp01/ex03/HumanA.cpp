/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:51:57 by ebella            #+#    #+#             */
/*   Updated: 2025/08/26 18:04:01 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
	std::cout << GREEN << name << " was created with his weapon: " << weapon.getType() << RESET << std::endl; 
}

HumanA::~HumanA()
{
	std::cout << RED << name << " was destroyed" << RESET << std::endl;
}

void	HumanA::attack()
{
	std::cout << YELLOW << name << " attacks with their " << weapon.getType() << RESET << std::endl;
}
void	HumanA::setWeapon(Weapon& weapon)
{
	this->weapon = weapon;
}

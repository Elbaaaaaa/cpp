/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:30:00 by ebella            #+#    #+#             */
/*   Updated: 2025/11/20 11:42:42 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->Hit = 100;
    this->Energy = 50;
    this->AttackDamage = 20;
	std::cout << GREEN << "ScavTrap " << this->name << " constructed (HP=" << this->Hit << ", Energy=" << this->Energy << ", Attack=" << this->AttackDamage << ")" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << MAGENTA << "ScavTrap " << this->name << " destructor called" << RESET << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    std::cout << ORANGE << "ScavTrap " << this->name << " ferociously attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << RESET << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << BLUE << "ScavTrap " << this->name << " is now in Gate keeper mode." << RESET << std::endl;
}

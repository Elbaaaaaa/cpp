/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:31:51 by ebella            #+#    #+#             */
/*   Updated: 2025/11/20 11:53:57 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name)
{
	this->Energy = 50;
	this->Hit = 100;
	this->AttackDamage = 20;
	std::cout << GREEN << "ClapTrap " << this->name << " constructed (HP=" << this->Hit << ", Energy=" << this->Energy << ", Attack=" << this->AttackDamage << ")" << RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->Hit <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->name << " has no hit points and cannot attack." << RESET << std::endl;
		return;
	}
	if (this->Energy <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->name << " has no energy and cannot attack." << RESET << std::endl;
		return;
	}
	this->Energy -= 1;
	std::cout << YELLOW << "ClapTrap " << this->name << " attacks " << target << ", causing " <<  this->AttackDamage << " points of damage! (Energy left: " << this->Energy << ")" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hit <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->name << " is already out of hit points." << RESET << std::endl;
		return;
	}
	this->Hit -= amount;
	if (this->Hit < 0)
		this->Hit = 0;
	std::cout << YELLOW << "ClapTrap " << this->name << " takes " << amount << " points of damage! (HP left: " << this->Hit << ")" << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hit <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->name << " has no hit points and cannot be repaired." << RESET << std::endl;
		return;
	}
	if (this->Energy <= 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->name << " has no energy and cannot be repaired." << RESET << std::endl;
		return;
	}
	this->Energy -= 1;
	this->Hit += amount;
	std::cout << YELLOW << "ClapTrap " << this->name << " is repaired by " << amount << " points! (HP: " << this->Hit << ", Energy left: " << this->Energy << ")" << RESET << std::endl;
}

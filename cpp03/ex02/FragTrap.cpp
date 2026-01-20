/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:53:48 by ebella            #+#    #+#             */
/*   Updated: 2025/11/20 11:54:32 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->Energy = 100;
	this->Hit = 100;
	this->AttackDamage = 30;
	std::cout << GREEN << "FragTrap " << this->name << " constructed (HP=" << this->Hit << ", Energy=" << this->Energy << ", Attack=" << this->AttackDamage << ")" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap destructor called" << RESET << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << CYAN << "FragTrap " << this->name << " requests a high five!" << RESET << std::endl;
}
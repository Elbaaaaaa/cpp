/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:16:05 by ebella            #+#    #+#             */
/*   Updated: 2025/11/20 11:46:56 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

int main( void )
{
	ClapTrap a("Elba");
	
	std::cout << std::endl;
	
	std::string target = "wolf";
	a.attack(target);
	a.takeDamage(5);
	a.beRepaired(5);
	
	std::cout << std::endl;
	
	ScavTrap s("Guardian");
	
	std::cout << std::endl;
	
	s.attack("bandit");
	s.guardGate();

	std::cout << std::endl;
	return 0;
}
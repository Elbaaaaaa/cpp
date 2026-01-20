/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:16:05 by ebella            #+#    #+#             */
/*   Updated: 2025/11/20 11:48:29 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main( void )
{
	std::cout << std::endl;
	ClapTrap clap("Clap");
	FragTrap frag("Frag");

	std::cout << std::endl;
	clap.attack("a wild target");
	clap.takeDamage(3);
	clap.beRepaired(5);

	std::cout << std::endl;
	frag.attack("an enemy");
	frag.takeDamage(20);
	frag.beRepaired(10);
	frag.highFivesGuys();

	std::cout << std::endl;
	return 0;
}
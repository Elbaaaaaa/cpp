/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:16:05 by ebella            #+#    #+#             */
/*   Updated: 2025/11/19 14:22:42 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

int main( void )
{
	ClapTrap a("josh");
	const std::string target = "wolf";
	
	a.attack(target);
	a.takeDamage(5);
	a.beRepaired(5);
	
	return 0;
}
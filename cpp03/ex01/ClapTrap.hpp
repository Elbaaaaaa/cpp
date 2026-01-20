/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:25:15 by ebella            #+#    #+#             */
/*   Updated: 2025/11/20 11:53:09 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define ORANGE "\033[38;5;208m"

class ClapTrap
{
	protected:
		std::string name;
		int Hit;
		int Energy;
		int AttackDamage;
	public:
		void    attack(const std::string& target);
		void    takeDamage(unsigned int amount);
		void    beRepaired(unsigned int amount);
		ClapTrap(std::string name);
		~ClapTrap();
};

#endif
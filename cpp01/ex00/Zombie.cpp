/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:47:42 by ebella            #+#    #+#             */
/*   Updated: 2025/08/26 15:01:44 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << YELLOW << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	Zombie::name = name;
	std::cout << GREEN << "Zombie: " << name << " was created" << RESET <<std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << "Zombie :" << name << " was destroyed" << RESET << std::endl;
}

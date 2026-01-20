/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:30:00 by ebella            #+#    #+#             */
/*   Updated: 2025/08/26 15:12:37 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
	Zombie* horde = zombieHorde(5, "Elba");
	if (!horde)
		return (1);
	for (int i = 0; i < 5; i++)
		horde[i].announce();
	
	delete[] horde;
	return (0);
}

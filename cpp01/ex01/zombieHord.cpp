/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHord.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:54:58 by ebella            #+#    #+#             */
/*   Updated: 2025/09/24 14:38:30 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie *newZombie = new Zombie[N];
	if (!newZombie)
		return (NULL);
	for (int i = 0; i < N; i++)
		newZombie[i] = Zombie(name);
	return (&newZombie[0]);
}

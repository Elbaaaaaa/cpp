/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:15:00 by ebella            #+#    #+#             */
/*   Updated: 2025/08/28 19:59:59 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* heapZombie = newZombie("HeapZombie");
	if (!heapZombie)
		return (0);
	heapZombie->announce();
	delete heapZombie;
	
	randomChump("StackZombie");
	
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:21:32 by ebella            #+#    #+#             */
/*   Updated: 2026/03/11 14:44:43 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseUtils.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	std::cout << BLUE << "=========== CPP06 EX02 TESTING ===========" << RESET << std::endl;

	for (int i = 0; i < 10; ++i)
	{
		Base *obj = generate();

		std::cout << ORANGE << "[Test " << i + 1 << "] identify(Base*): " << RESET;
		identify(obj);

		std::cout << ORANGE << "[Test " << i + 1 << "] identify(Base&): " << RESET;
		identify(*obj);

		delete obj;
		std::cout << std::endl;
	}

	std::cout << YELLOW << "[Extra] identify(NULL): " << RESET;
	identify((Base *)NULL);

	return 0;
}

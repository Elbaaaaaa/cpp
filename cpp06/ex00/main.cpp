/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:11:47 by ebella            #+#    #+#             */
/*   Updated: 2026/02/09 11:11:47 by ebella            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./ScalarConverter <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}

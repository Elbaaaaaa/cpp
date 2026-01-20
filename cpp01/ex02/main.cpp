/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:05:14 by ebella            #+#    #+#             */
/*   Updated: 2025/08/26 16:26:41 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int		main()
{
	std::string *stringPTR;
	std::string string = "HI THIS IS BRAIN";

	stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "adress of string: " << &string << std::endl;
	std::cout << "adress of stringPTR: " << stringPTR << std::endl;
	std::cout << "adress of stringREF: " << &stringREF << std::endl; 

	std::cout << "value of string: " << string << std::endl; 
	std::cout << "value of stringPTR: " << *stringPTR << std::endl; 
	std::cout << "value of stringREF: " << stringREF << std::endl;

	return (0);
}
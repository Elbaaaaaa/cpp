/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:47:28 by ebella            #+#    #+#             */
/*   Updated: 2026/01/20 14:01:56 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << CYAN << "\n=== Test 1: Valid Bureaucrat ===" << RESET << std::endl;
	try
	{
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 2: Grade Too High (0) ===" << RESET << std::endl;
	try
	{
		Bureaucrat alice("Alice", 0);
		std::cout << alice << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 3: Grade Too Low (151) ===" << RESET << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 151);
		std::cout << charlie << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 4: Increment Grade ===" << RESET << std::endl;
	try
	{
		Bureaucrat dave("Dave", 3);
		std::cout << dave << std::endl;
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 5: Decrement Grade ===" << RESET << std::endl;
	try
	{
		Bureaucrat eve("Eve", 148);
		std::cout << eve << std::endl;
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 6: Edge Cases (1 and 150) ===" << RESET << std::endl;
	try
	{
		Bureaucrat top("TopGuy", 1);
		Bureaucrat bottom("BottomGuy", 150);
		std::cout << top << std::endl;
		std::cout << bottom << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 7: Copy Constructor ===" << RESET << std::endl;
	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	return 0;
}

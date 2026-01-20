/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:47:28 by ebella            #+#    #+#             */
/*   Updated: 2026/01/20 14:14:11 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << CYAN << "\n========== FORM TESTS ==========" << RESET << std::endl;

	std::cout << CYAN << "\n=== Test 1: Valid Form Creation ===" << RESET << std::endl;
	try
	{
		Form form1("Form A", 50, 100);
		std::cout << form1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 2: Form with Grade Too High (Sign) ===" << RESET << std::endl;
	try
	{
		Form form2("Form B", 0, 100);
		std::cout << form2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 3: Form with Grade Too Low (Execute) ===" << RESET << std::endl;
	try
	{
		Form form3("Form C", 50, 151);
		std::cout << form3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 4: Form Edge Cases (1 and 150) ===" << RESET << std::endl;
	try
	{
		Form form4("Form D", 1, 150);
		std::cout << form4 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n========== FORM SIGNING TESTS ==========" << RESET << std::endl;

	std::cout << CYAN << "\n=== Test 5: Bureaucrat Successfully Signs Form ===" << RESET << std::endl;
	try
	{
		Bureaucrat bob("Bob", 30);
		Form form5("Form E", 50, 100);
		
		std::cout << "Before signing:" << std::endl;
		std::cout << form5 << std::endl;
		
		bob.signForm(form5);
		
		std::cout << "After signing:" << std::endl;
		std::cout << form5 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 6: Bureaucrat Cannot Sign (Grade Too Low) ===" << RESET << std::endl;
	try
	{
		Bureaucrat alice("Alice", 100);
		Form form6("Form F", 50, 100);
		
		std::cout << "Before signing:" << std::endl;
		std::cout << form6 << std::endl;
		
		alice.signForm(form6);
		
		std::cout << "After signing:" << std::endl;
		std::cout << form6 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 7: Multiple Bureaucrats and Forms ===" << RESET << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat employee("Employee", 75);
		Bureaucrat trainee("Trainee", 150);
		
		Form document1("Tax Form", 50, 100);
		Form document2("Secret Report", 1, 1);
		
		std::cout << "\n--- Document 1: Tax Form ---" << std::endl;
		boss.signForm(document1);
		employee.signForm(document1);
		trainee.signForm(document1);
		
		std::cout << "\n--- Document 2: Secret Report ---" << std::endl;
		boss.signForm(document2);
		employee.signForm(document2);
		trainee.signForm(document2);
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 8: Form Copy Constructor ===" << RESET << std::endl;
	try
	{
		Form original("Original", 50, 100);
		Form copy(original);
		
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << CYAN << "\n=== Test 9: Boundary Test - Grade Exactly at Requirement ===" << RESET << std::endl;
	try
	{
		Bureaucrat exact("Exact", 50);
		Form boundary("Boundary Form", 50, 100);
		
		std::cout << "Bureaucrat grade: " << exact.getGrade() << std::endl;
		std::cout << "Form requires grade: " << boundary.getGradeToSign() << std::endl;
		exact.signForm(boundary);
		std::cout << boundary << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	return 0;
}

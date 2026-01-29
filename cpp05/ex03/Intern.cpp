/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by ebella            #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << CYAN << "Intern Default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << CYAN << "Intern Copy constructor called" << RESET << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << CYAN << "Intern Assignment operator called" << RESET << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << RED << "Intern Destructor called" << RESET << std::endl;
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Form not found :(";
}

const std::string Intern::names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

const Intern::CF Intern::forms[3] = { &Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm};

AForm* Intern::createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
		{
			AForm* form = forms[i](target);
			std::cout << GREEN << "Intern creates " << form->getName() << RESET << std::endl;
			return form;
		}
	}
	throw FormNotFoundException();
}

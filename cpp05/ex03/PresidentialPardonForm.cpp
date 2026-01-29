/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:16:51 by ebella            #+#    #+#             */
/*   Updated: 2026/01/24 13:18:56 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "Default", 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	std::cout << GREEN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << YELLOW << "PresidentialPardonForm assignment operator called" << RESET << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

void PresidentialPardonForm::performAction() const 
{
	std::cout << BLUE << this->getTarget() << " Has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

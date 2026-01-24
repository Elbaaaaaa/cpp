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

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm(target, 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

void PresidentialPardonForm::performAction() const 
{
	std::cout << BLUE << this->getName() << " Has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

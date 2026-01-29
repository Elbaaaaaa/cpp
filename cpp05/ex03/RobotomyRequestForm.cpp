/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:00:36 by ebella            #+#    #+#             */
/*   Updated: 2026/01/24 13:13:38 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "Default", 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	std::cout << GREEN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << YELLOW << "RobotomyRequestForm assignment operator called" << RESET << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

void RobotomyRequestForm::performAction() const 
{
    std::cout << "* VRRRRRRR... BZZZZZZZ... *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << BLUE << this->getTarget() << " has been robotomized successfully !" << RESET << std::endl;
	else
		std::cout << YELLOW << this->getTarget() << " robotomy has failed." << RESET << std::endl;			
}

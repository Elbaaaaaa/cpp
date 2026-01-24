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

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm(target, 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

void RobotomyRequestForm::performAction() const 
{
	std::srand(std::time(NULL));
	
	if (std::rand() % 2 == 0)
		std::cout << BLUE << this->getName() << " has been robotomized successfully !" << RESET << std::endl;
	else
		std::cout << YELLOW << this->getName() << " robotomy has failed." << RESET << std::endl;			
}

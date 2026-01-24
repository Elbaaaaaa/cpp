/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:47:28 by ebella            #+#    #+#             */
/*   Updated: 2026/01/24 13:20:21 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << MAGENTA << "========== TESTS MODULE 05 EX02 ==========" << RESET << std::endl;

    try {
        Bureaucrat president("President", 1);
        Bureaucrat lowLevel("Stagiaire", 150);
        Bureaucrat midLevel("Chef de bureau", 40);

        ShrubberyCreationForm shrub("Jardin");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Criminel");

        std::cout << CYAN << "\n--- Test 1: Shrubbery (Sign 145, Exec 137) ---" << RESET << std::endl;
        lowLevel.signForm(shrub);
        midLevel.signForm(shrub);
        lowLevel.executeForm(shrub);
        midLevel.executeForm(shrub);

        std::cout << CYAN << "\n--- Test 2: Robotomy (Sign 72, Exec 45) ---" << RESET << std::endl;
        midLevel.signForm(robot); 
        midLevel.executeForm(robot); 

        std::cout << CYAN << "\n--- Test 3: Presidential Pardon (Sign 25, Exec 5) ---" << RESET << std::endl;
        midLevel.signForm(pardon); 
        president.signForm(pardon); 
        midLevel.executeForm(pardon); 
        president.executeForm(pardon); 

        std::cout << CYAN << "\n--- Test 4: Exécuter un formulaire non signé ---" << RESET << std::endl;
        RobotomyRequestForm robot2("Calculateur");
        president.executeForm(robot2);

    } catch (std::exception &e) {
        std::cout << RED << "Exception imprévue : " << e.what() << RESET << std::endl;
    }

    return 0;
}
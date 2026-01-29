/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:47:28 by ebella            #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(NULL));
    std::cout << MAGENTA << "========== TESTS MODULE 05 EX03 - INTERN ==========" << RESET << std::endl;

    try {
        Bureaucrat president("President", 1);
        Bureaucrat midLevel("Chef de bureau", 40);

        std::cout << CYAN << "\n--- Test 1: Intern crée un RobotomyRequestForm ---" << RESET << std::endl;
        {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
            if (rrf)
            {
                std::cout << *rrf << std::endl;
                president.signForm(*rrf);
                president.executeForm(*rrf);
                delete rrf;
            }
        }

        std::cout << CYAN << "\n--- Test 2: Intern crée un ShrubberyCreationForm ---" << RESET << std::endl;
        {
            Intern intern;
            AForm* shrub = intern.makeForm("shrubbery creation", "Home");
            if (shrub)
            {
                std::cout << *shrub << std::endl;
                midLevel.signForm(*shrub);
                midLevel.executeForm(*shrub);
                delete shrub;
            }
        }

        std::cout << CYAN << "\n--- Test 3: Intern crée un PresidentialPardonForm ---" << RESET << std::endl;
        {
            Intern intern;
            AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
            if (pardon)
            {
                std::cout << *pardon << std::endl;
                president.signForm(*pardon);
                president.executeForm(*pardon);
                delete pardon;
            }
        }

        std::cout << CYAN << "\n--- Test 4: Intern essaie de créer un formulaire inexistant ---" << RESET << std::endl;
        {
            Intern intern;
            try {
                AForm* unknown = intern.makeForm("unknown form", "Nobody");
                delete unknown; // Ne sera jamais atteint
            } catch (std::exception& e) {
                std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
            }
        }

        std::cout << CYAN << "\n--- Test 5: Cas limites ---" << RESET << std::endl;
        {
            Intern intern;
            // Test avec des noms incorrects
            try {
                AForm* bad1 = intern.makeForm("Robotomy Request", "Test"); // Mauvaise casse
                delete bad1;
            } catch (std::exception& e) {
                std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
            }
            try {
                AForm* bad2 = intern.makeForm("shrubbery", "Test"); // Nom incomplet
                delete bad2;
            } catch (std::exception& e) {
                std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
            }
            try {
                AForm* bad3 = intern.makeForm("", "Test"); // Nom vide
                delete bad3;
            } catch (std::exception& e) {
                std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
            }
        }

    } catch (std::exception &e) {
        std::cout << RED << "Exception imprévue : " << e.what() << RESET << std::endl;
    }

    std::cout << MAGENTA << "\n========== FIN DES TESTS ==========" << RESET << std::endl;
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:47:28 by ebella            #+#    #+#             */
/*   Updated: 2026/01/22 16:39:00 by ebella           ###   ########.fr       */
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
        // 1. Création des Bureaucrates
        Bureaucrat president("President", 1);
        Bureaucrat lowLevel("Stagiaire", 150);
        Bureaucrat midLevel("Chef de bureau", 40);

        // 2. Création des Formulaires
        ShrubberyCreationForm shrub("Jardin");      // Sign: 145, Exec: 137
        // RobotomyRequestForm robot("Bender");        // Sign: 72, Exec: 45
        // PresidentialPardonForm pardon("Criminel");  // Sign: 25, Exec: 5

        std::cout << CYAN << "\n--- Test 1: Shrubbery (Sign 145, Exec 137) ---" << RESET << std::endl;
        lowLevel.signForm(shrub); // Devrait échouer (Grade 150 < 145)
        midLevel.signForm(shrub); // Devrait réussir
        lowLevel.executeForm(shrub); // Devrait échouer (Grade 150 < 137)
        midLevel.executeForm(shrub); // Devrait réussir (Crée le fichier Jardin_shrubbery)
		shrub.performAction();

        // std::cout << CYAN << "\n--- Test 2: Robotomy (Sign 72, Exec 45) ---" << RESET << std::endl;
        // midLevel.signForm(robot); // Réussit (40 < 72)
        // midLevel.executeForm(robot); // Réussit (40 < 45) - 50% de chance de succès

        // std::cout << CYAN << "\n--- Test 3: Presidential Pardon (Sign 25, Exec 5) ---" << RESET << std::endl;
        // midLevel.signForm(pardon); // Échoue (40 n'est pas assez haut pour 25)
        // president.signForm(pardon); // Réussit
        // midLevel.executeForm(pardon); // Échoue (40 < 5)
        // president.executeForm(pardon); // Réussit

        // std::cout << CYAN << "\n--- Test 4: Exécuter un formulaire non signé ---" << RESET << std::endl;
        // RobotomyRequestForm robot2("Calculateur");
        // president.executeForm(robot2); // Doit dire que le formulaire n'est pas signé

    } catch (std::exception &e) {
        std::cout << RED << "Exception imprévue : " << e.what() << RESET << std::endl;
    }

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:49:01 by ebella            #+#    #+#             */
/*   Updated: 2026/01/22 16:37:15 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145, 137)
{
	std::cout << GREEN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(target, 145, 137)
{
	std::cout << GREEN << "ShrubberyCreationForm constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

void ShrubberyCreationForm::performAction() const {
    std::ofstream ofs((this->getName() + "_shrubbery").c_str());
    if (ofs.is_open()) {
        ofs << "    oxoxoo    ooxoo\n"
               "  ooxoxo oo  oxoxooo\n"
               " oooo xxoxoo ooo ooox\n"
               " oxo o oxoxo  xoxxoxo\n"
               "  oxo xooxoooo o ooo\n"
               "    ooo\\oo\\  /o/o\n"
               "        \\  \\/ /\n"
               "         |   /\n"
               "         |  |\n"
               "         | D|\n"
               "         |  |\n"
               "         |  |\n"
               "  ______/____\\____\n";
        ofs.close();
    }
}

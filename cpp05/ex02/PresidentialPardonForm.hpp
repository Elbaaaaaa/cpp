/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:16:01 by ebella            #+#    #+#             */
/*   Updated: 2026/01/24 13:16:38 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include "AForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define ORANGE "\033[38;5;208m"

class PresidentialPardonForm : public AForm
{		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		
		virtual void performAction() const;		
};

#endif
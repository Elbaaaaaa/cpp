/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:00:00 by ebella            #+#    #+#             */
/*   Updated: 2026/01/29 10:00:00 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define ORANGE  "\033[38;5;208m"

class Intern
{
	private:

	typedef AForm* (*CF)(const std::string& target);

	static const std::string	names[3];
	static const CF				forms[3];

	static AForm* createShrubberyForm(const std::string& target);
	static AForm* createRobotomyForm(const std::string& target);
	static AForm* createPresidentialForm(const std::string& target);
	
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target);

		class FormNotFoundException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif

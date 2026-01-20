/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:08:27 by ebella            #+#    #+#             */
/*   Updated: 2026/01/20 14:17:57 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(lowestGrade), gradeToExecute(lowestGrade)
{
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) 
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << GREEN << "Form constructor called" << RESET << std::endl;
	if (gradeToSign < highestGrade || gradeToExecute < highestGrade)
		throw GradeTooHighException();
	if (gradeToSign > lowestGrade || gradeToExecute > lowestGrade)
		throw GradeTooLowException();
}

Form::Form(const Form& other) 
	: name(other.name), isSigned(other.isSigned), 
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << YELLOW << "Form assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

Form::~Form()
{
	std::cout << RED << "Form destructor called" << RESET << std::endl;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high! (minimum grade is 1)";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low! (maximum grade is 150)";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << ", form status: " << (form.getIsSigned() ? "signed" : "unsigned")
		<< ", grade to sign: " << form.getGradeToSign() 
		<< ", grade to execute: " << form.getGradeToExecute();
	return out;
}

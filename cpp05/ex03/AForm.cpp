/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 14:08:27 by ebella            #+#    #+#             */
/*   Updated: 2026/01/22 16:19:18 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), target("Default"), isSigned(false), gradeToSign(lowestGrade), gradeToExecute(lowestGrade)
{
	std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(std::string const &name, std::string const &target, int gradeToSign, int gradeToExecute) 
	: name(name), target(target), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	std::cout << GREEN << "AForm constructor called" << RESET << std::endl;
	if (gradeToSign < highestGrade || gradeToExecute < highestGrade)
		throw GradeTooHighException();
	if (gradeToSign > lowestGrade || gradeToExecute > lowestGrade)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) 
	: name(other.name), target(other.target), isSigned(other.isSigned), 
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << GREEN << "AForm copy constructor called" << RESET << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << YELLOW << "AForm assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm()
{
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
}

std::string AForm::getName() const
{
	return this->name;
}

std::string AForm::getTarget() const
{
	return this->target;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	this->isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();

	this->performAction();
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form Not Signed ! (please make sure to sign it first)";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high! (minimum grade is 1)";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low! (maximum grade is 150)";
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
	out << "Form " << AForm.getName() << " (target: " << AForm.getTarget() << "), status: " << (AForm.getIsSigned() ? "signed" : "unsigned")
		<< ", grade to sign: " << AForm.getGradeToSign() 
		<< ", grade to execute: " << AForm.getGradeToExecute();
	return out;
}

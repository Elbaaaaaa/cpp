/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:42:11 by ebella            #+#    #+#             */
/*   Updated: 2025/09/24 14:33:00 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	value = 0;
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	this->value = fixed.value;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
	if (this != &fixed)
	{
		this->value = fixed.value;
	}
	return *this;
}

bool Fixed::operator>(const Fixed& fixed)
{
	return (this->value > fixed.value);
}

bool Fixed::operator<(const Fixed& fixed)
{
	return (this->value < fixed.value);
}

bool Fixed::operator>=(const Fixed& fixed)
{
	return (this->value >= fixed.value);
}

bool Fixed::operator<=(const Fixed& fixed)
{
	return (this->value <= fixed.value);
}

bool Fixed::operator==(const Fixed& fixed)
{
	return (this->value == fixed.value);
}

bool Fixed::operator!=(const Fixed& fixed)
{
	return (this->value != fixed.value);
}

Fixed Fixed::operator+(const Fixed& fixed)
{
	Fixed result;
	result.value = this->value + fixed.value;
	return result;
}

Fixed Fixed::operator-(const Fixed& fixed)
{
	Fixed result;
	result.value = this->value - fixed.value;
	return result;
}

Fixed Fixed::operator*(const Fixed& fixed)
{
	Fixed result;
	result.value = (this->value * fixed.value) >> bits;
	return result;
}

Fixed Fixed::operator/(const Fixed& fixed)
{
	Fixed result;
	result.value = (this->value << bits) / fixed.value;
	return result;
}

Fixed Fixed::min(Fixed& fixed, Fixed& fixed2)
{
	return (fixed.value < fixed2.value ? fixed : fixed2);
}
Fixed Fixed::min(const Fixed& fixed,const Fixed& fixed2)
{
	return (fixed.value < fixed2.value ? fixed : fixed2);
}
Fixed Fixed::max(Fixed& fixed, Fixed& fixed2)
{
	return (fixed.value > fixed2.value ? fixed : fixed2);
}
Fixed Fixed::max(const Fixed& fixed,const Fixed& fixed2)
{
	return (fixed.value > fixed2.value ? fixed : fixed2);
}

Fixed& Fixed::operator++()
{
	value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->value;
	return (temp);
}

Fixed& Fixed::operator--()
{
	value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->value;
	return (temp);
}

int Fixed::getRawBits() const
{
	std::cout << YELLOW << "getRawBits member function is called" << RESET << std::endl;
	return this->value;
}

void Fixed::setRawBits(const int raw)
{
	this->value = raw;
}

Fixed::Fixed(const int value)
{
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
	this->value = value << bits;
}

Fixed::Fixed(const float value)
{
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
	this->value = roundf(value * (1 << bits));
}

float Fixed::toFloat() const
{
	return (float)this->value / (1 << bits);
}

int Fixed::toInt(void) const
{
	return this->value >> bits;
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return o;
}

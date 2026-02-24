/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:20:03 by ebella            #+#    #+#             */
/*   Updated: 2026/02/12 14:20:03 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Serializer default constructor called" << RESET << std::endl;
}

Serializer::~Serializer()
{
	std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
	std::cout << GREEN << "Serializer copy constructor called" << RESET << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
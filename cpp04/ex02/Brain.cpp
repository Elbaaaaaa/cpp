/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:35:21 by ebella            #+#    #+#             */
/*   Updated: 2025/11/22 16:05:05 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "Default Brain constructor called" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << RED << "Brain Destructor called" << RESET << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << GREEN << "Copy Brain constructor called" << RESET << std::endl;
}

void Brain::setIdea(int idx, const std::string& idea)
{
	if (idx < 0 || idx >= 100)
		return;
	this->ideas[idx] = idea;
}

std::string Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
		return std::string();
	return this->ideas[idx];
}

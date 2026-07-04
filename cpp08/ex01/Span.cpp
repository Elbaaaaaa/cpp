/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:04:52 by ebella            #+#    #+#             */
/*   Updated: 2026/06/14 14:11:39 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : N(N)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span& other)
{
	(void)other;
	std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& other)
{
	(void)other;
	return *this;
}

void Span::addNumber(int number)
{
	if (_numbers.size() < N)
		_numbers.push_back(number);
	else
		throw std::runtime_error("Too many items in array.");
}

		
unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Array too smol !");
	
	unsigned int min_diff =  4294967295;
	std::vector<int> copy = _numbers;
	
	std::sort(copy.begin(), copy.end());
	
	for (unsigned int i = 0; i < copy.size() - 1; i++)
	{
		unsigned int min_diff_res = copy[i + 1] - copy[i];
		if (min_diff_res <  min_diff)
			min_diff = min_diff_res;
	}
	
	return min_diff;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Array too smol !");
	
	std::vector<int>::const_iterator iterator_max = std::max_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator iterator_min= std::min_element(_numbers.begin(), _numbers.end());
	
	return  abs(*iterator_max - *iterator_min);
}
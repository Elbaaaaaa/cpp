/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:04:55 by ebella            #+#    #+#             */
/*   Updated: 2026/06/14 14:12:01 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>

class Span
{
	private:
		unsigned int N;
		std::vector<int> _numbers;
	
	public :
		~Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span &other);

		template<typename T>
		void addNumber(T begin, T end)
		{
		    unsigned int dist = std::distance(begin, end);
		
		    if (dist + _numbers.size() > N)
		        throw std::runtime_error("Error: Not enough space");
		    _numbers.insert(_numbers.end(), begin, end);
		}
		
		void 		 addNumber(int number);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

};

# endif
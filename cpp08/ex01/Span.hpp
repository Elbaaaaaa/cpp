/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:04:55 by ebella            #+#    #+#             */
/*   Updated: 2026/06/04 13:51:29 by ebella           ###   ########.fr       */
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

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

};

# endif
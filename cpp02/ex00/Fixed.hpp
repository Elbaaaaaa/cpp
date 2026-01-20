/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:20:15 by ebella            #+#    #+#             */
/*   Updated: 2025/08/30 16:05:42 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_H
# define FIXED_H

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define ORANGE "\033[38;5;208m"

class Fixed
{
	private:
		int value;
		static const int bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		~Fixed();
		Fixed & operator=(const Fixed& fixed);
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

# endif

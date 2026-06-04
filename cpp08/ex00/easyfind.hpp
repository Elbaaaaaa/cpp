/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:40:04 by ebella            #+#    #+#             */
/*   Updated: 2026/06/04 13:05:29 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept> 
# include <algorithm>
# include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int i)
{
	typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), i);
	if (it != container.end())
		return it;
	else
		throw std::runtime_error("Element not found in the container.");
}

# endif
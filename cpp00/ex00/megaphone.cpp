/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:28:24 by ebella            #+#    #+#             */
/*   Updated: 2025/08/24 17:29:39 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2 || (!argv[1][0] && argc == 2))
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (1);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		
		for(int j = 0; j < (int)arg.length(); j++)
			std::cout << (char)std::toupper(arg[j]);
		if (i < argc - 1)
			std::cout << " ";
	}

	std::cout <<std::endl;
	return (0);
}

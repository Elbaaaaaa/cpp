/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 13:02:47 by ebella            #+#    #+#             */
/*   Updated: 2025/08/27 14:44:05 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>
# include <string>

int		main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	std::ifstream file(argv[1]);
	if (!file)
		return (1);
	std::string line;
	std::string word = argv[2];
	std::string replace = argv[3];
	std::string outFileName = std::string(argv[1]) + ".replace";
	std::ofstream outFile(outFileName.c_str());

	while(std::getline(file, line))
	{
		for (size_t i = 0; i < line.length(); i++)
		{
			if (line.substr(i, word.length()) == word)
			{
				outFile << replace;
				i += word.length() - 1;
			}
			else
				outFile << line[i];
		}
		outFile << std::endl;
	}
	outFile.close();
	return (0);	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 11:04:03 by ebella            #+#    #+#             */
/*   Updated: 2026/06/26 12:06:51 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>


class BitcoinExchange 
{
	private :
			std::map<std::string, double> _data;
	
	public :
			BitcoinExchange();
			~BitcoinExchange();
			BitcoinExchange(const BitcoinExchange &other);
			BitcoinExchange& operator=(const BitcoinExchange &other);

			void	LoadDatabase(std::string filename);
			void	ProcessInput(std::string filename);
			bool 	isValidDate(const std::string &date);
			

			class FileNotLoaded : public std::exception {
				public:
					virtual const char* what() const throw() {
						return "Error: File did not load correctly.";
					}
			};
			class FileWrongFormat : public std::exception {
				public:
					virtual const char* what() const throw() {
						return "Error: Data in wrong format.";
					}
			};

			
			class EmptyDatabase : public std::exception {
				public:
					virtual const char* what() const throw() {
						return "Error: Database is empty.";
					}
			};
};











#endif
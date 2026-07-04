/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 12:45:31 by ebella            #+#    #+#             */
/*   Updated: 2026/06/23 16:08:17 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
        this->_data = other._data;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::LoadDatabase(std::string filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	std::string s_date;
	std::string s_price;
	
	if (!file.is_open())
		throw FileNotLoaded();
	else
	{
		getline(file, line);
		while (getline(file, line))
		{
			if (line.empty())
				continue;
			size_t pos = line.find(',');
			if (pos == std::string::npos)
				throw FileWrongFormat();
			
			s_date = line.substr(0, pos);
			s_price = line.substr(pos + 1);
			
			double d_price = std::atof(s_price.c_str());
			
			if (isValidDate(s_date))
				_data[s_date] = d_price;
		}
		file.close();
	}
}

bool 	BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.empty() || date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue ;
		else if (!std::isdigit(date[i]))
			return false;
	}
	
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	if (month < 1 || month > 12)
		return false;
	
	bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLeap)
		daysInMonth[1] = 29;
	
	if (day < 1 || day > daysInMonth[month - 1])
		return false;

	if (year < 2009 || (year == 2009 && month == 1 && day < 2))
		return false;

	return true;
}

void	BitcoinExchange::ProcessInput(std::string filename)
{
	std::ifstream file(filename.c_str());
	std::string line;
	std::string s_date;
	std::string s_value;
	
	if (!file.is_open())
		throw FileNotLoaded();
	
	if (_data.empty())
		throw EmptyDatabase();	
		
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t sep = line.find('|');
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		s_date = line.substr(0, sep);
		s_value = line.substr(sep + 1);
		
		size_t first = s_date.find_first_not_of(" \t");
		size_t last  = s_date.find_last_not_of(" \t");
		if (first != std::string::npos && last != std::string::npos)
			s_date = s_date.substr(first, last - first + 1);
	
		size_t first_value = s_value.find_first_not_of(" \t");
		size_t last_value  = s_value.find_last_not_of(" \t");
		if (first_value != std::string::npos && last_value != std::string::npos)
			s_value = s_value.substr(first_value, last_value - first_value + 1);

		if (!isValidDate(s_date))
		{
			std::cout << "Error: bad input => " << s_date << std::endl;
			continue;
		}
		
		double d_value = atof(s_value.c_str());
		if (d_value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (d_value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		
		std::map<std::string, double>::iterator it = _data.lower_bound(s_date);
		if (it == _data.end() || (it != _data.begin() && it->first != s_date))
		{
			--it;
		}
		
		if (it == _data.end() || (it == _data.begin() && it->first > s_date))
		{
			std::cout << "Error: bad input => " << std::endl;
			continue;
		}
		
		double res = d_value * it->second;
		std::cout << s_date << " => " << s_value << " = " << res << std::endl;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:11:53 by ebella            #+#    #+#             */
/*   Updated: 2026/02/09 11:11:53 by ebella            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <cctype>

namespace
{
	enum e_type { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_INVALID };

	bool isCharLiteral(const std::string& s)
	{
		if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
			return true;
		if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
			return true;
		return false;
	}

	bool isSpecialDouble(const std::string& s)
	{
		return s == "nan" || s == "inf" || s == "+inf" || s == "-inf";
	}

	bool isIntLiteral(const std::string& s)
	{
		size_t i = 0;
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (i >= s.length())
			return false;
		while (i < s.length())
		{
			if (!std::isdigit(s[i]))
				return false;
			i++;
		}
		return true;
	}

	bool isFloatLiteral(const std::string& s)
	{
		if (s.length() < 2)
			return false;
		char last = s[s.length() - 1];
		if (last != 'f' && last != 'F')
			return false;
		return true;
	}

	bool isDoubleLiteral(const std::string& s)
	{
		size_t i = 0;
		if (s[i] == '+' || s[i] == '-')
			i++;
		bool has_dot = false;
		bool has_digit = false;
		for (; i < s.length(); i++)
		{
			if (s[i] == '.')
			{
				if (has_dot)
					return false;
				has_dot = true;
			}
			else if (std::isdigit(static_cast<unsigned char>(s[i])))
				has_digit = true;
			else
				return false;
		}
		return has_digit;
	}

	e_type detectType(const std::string& literal)
	{
		if (literal.empty())
			return TYPE_INVALID;
		if (isCharLiteral(literal))
			return TYPE_CHAR;
		if (isFloatLiteral(literal))
			return TYPE_FLOAT;
		if (isIntLiteral(literal))
			return TYPE_INT;
		if (isSpecialDouble(literal) || isDoubleLiteral(literal))
			return TYPE_DOUBLE;
		if (literal.length() == 1)
			return TYPE_CHAR;
		return TYPE_INVALID;
	}

	void printChar(double value, bool fromChar, char c)
	{
		std::cout << "char: ";
		if (fromChar)
		{
			if (static_cast<unsigned char>(c) < 32 || static_cast<unsigned char>(c) == 127)
				std::cout << "Non displayable" << std::endl;
			else
				std::cout << "'" << c << "'" << std::endl;
			return;
		}
		if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
			std::cout << "impossible" << std::endl;
		else if (value < 32 || value == 127)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	}

	void printInt(double value, bool fromChar, char c)
	{
		std::cout << "int: ";
		if (fromChar)
		{
			std::cout << static_cast<int>(static_cast<unsigned char>(c)) << std::endl;
			return;
		}
		if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(value) << std::endl;
	}

	void printFloat(double value, bool fromChar, char c)
	{
		std::cout << "float: ";
		float f = fromChar ? static_cast<float>(static_cast<unsigned char>(c)) : static_cast<float>(value);
		if (std::isnan(f))
			std::cout << "nanf" << std::endl;
		else if (std::isinf(f))
			std::cout << (f > 0 ? "" : "-") << "inff" << std::endl;
		else if (f == static_cast<float>(static_cast<int>(f)) && f >= -1e6 && f <= 1e6)
			std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		else
			std::cout << std::setprecision(7) << f << "f" << std::endl;
	}

	void printDouble(double value, bool fromChar, char c)
	{
		std::cout << "double: ";
		double d = fromChar ? static_cast<double>(static_cast<unsigned char>(c)) : value;
		if (std::isnan(d))
			std::cout << "nan" << std::endl;
		else if (std::isinf(d))
			std::cout << (d > 0 ? "" : "-") << "inf" << std::endl;
		else if (d == static_cast<double>(static_cast<int>(d)) && d >= -1e6 && d <= 1e6)
			std::cout << std::fixed << std::setprecision(1) << d << std::endl;
		else
			std::cout << std::setprecision(15) << d << std::endl;
	}
}

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "ScalarConverter default constructor called" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
	std::cout << GREEN << "ScalarConverter copy constructor called" << RESET << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter destructor called" << RESET << std::endl;
}

void ScalarConverter::convert(std::string literal)
{
	e_type type = detectType(literal);
	if (type == TYPE_INVALID)
	{
		std::cout << RED << "Error: invalid literal" << RESET << std::endl;
		return;
	}

	double value = 0;
	char charVal = 0;
	bool fromChar = false;

	switch (type)
	{
		case TYPE_CHAR:
			charVal = literal.length() == 1 ? literal[0] : literal[1];
			value = static_cast<double>(static_cast<unsigned char>(charVal));
			fromChar = true;
			break;
		case TYPE_INT:
			value = static_cast<double>(std::atoi(literal.c_str()));
			break;
		case TYPE_FLOAT:
		case TYPE_DOUBLE:
			value = std::atof(literal.c_str());
			break;
		default:
			return;
	}

	printChar(value, fromChar, charVal);
	printInt(value, fromChar, charVal);
	printFloat(value, fromChar, charVal);
	printDouble(value, fromChar, charVal);
}

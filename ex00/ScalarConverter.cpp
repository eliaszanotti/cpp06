/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/18 18:18:50 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits>
#include <stdlib.h>
#include <iomanip>
#include "ScalarConverter.hpp"

// isType
static bool isChar(std::string const &string)
{
	if (string.length() != 1)
		return (false);
	if (string[0] < std::numeric_limits<char>::min() \
		|| string[0] > std::numeric_limits<char>::max() \
		|| isdigit(string[0]))
		return (false);
	return (true);
}

static bool isInt(std::string const &string)
{
	size_t	i = 0;

	if (string[i] == '-')
		i++;
	for (; i < string.length(); i++)	
	{
		if (!isdigit(string[i]))
			return (false);
	}
	return (true);
}

static bool isFloat(std::string const &string)
{
	bool	hasPoint = false;

	if (string == "-inff" || string == "+inff" || string == "nanf")
		return (true);
	if (string[string.length() - 1] != 'f')
		return (false);
	for (size_t i = 0; i < string.length() - 1; i++)
	{
		if (string[i] == '.')
		{
			if (hasPoint)
				return (false);
			hasPoint = true;
		}
		else if (!isdigit(string[i]))
			return (false);
	}
    return (true);
}

static bool isDouble(std::string const &string)
{
	bool	hasPoint = false;

	if (string == "-inf" || string == "+inf" || string == "nan")
		return (true);
	for (size_t i = 0; i < string.length(); i++)
	{
		if (string[i] == '.')
		{
			if (hasPoint)
				return (false);
			hasPoint = true;
		}
		else if (!isdigit(string[i]))
			return (false);
	}
	return (true);
}

static bool isSpecialNumber(std::string const &string)
{
	if (string == "-inff" || string == "+inff" || string == "nanf" || \
		string == "-inf" || string == "+inf" || string == "nan")
		return (true);
	return (false);
}

type    getType(std::string const &string)
{
	if (isChar(string))
		return (_char);
	if (isInt(string))
		return (_int);
	if (isFloat(string))
		return (_float);
	if (isDouble(string))
		return (_double);
	return (_error);
}

// toType
void toChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void toInt(std::string const &string, int number)
{
	std::ostringstream	convert;

	convert << number;
	if (convert.str() != string)
	{
		std::cout << "\e[31m[ERROR]\e[0m Overflow" << std::endl;
		return ;
	}
	if (number >= 32 && number <= 126)
		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
	else	
		std::cout << "char: non printable char" << std::endl;
	std::cout << "int: " << number << std::endl;
	std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(number) << ".0" << std::endl;
}

void toFloat(std::string const &string, float number)
{
	std::ostringstream	convert;

	convert << std::fixed << std::setprecision(1) << number;
	if (convert.str() != string)
	{
		std::cout << "\e[31m[ERROR]\e[0m Overflow" << std::endl;
		return ;
	}
	if (isprint(number))
		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
	else	
		std::cout << "char: non printable char" << std::endl;
	std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << "float: " << number << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(number) << ".0" << std::endl;
}

void toDouble(std::string const &string, double number)
{
	std::ostringstream	convert;

	convert << std::fixed << std::setprecision(1) << number;
	if (convert.str() != string)
	{
		std::cout << "\e[31m[ERROR]\e[0m Overflow" << std::endl;
		return ;
	}
	if (isprint(number))
		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
	else	
		std::cout << "char: non printable char" << std::endl;
	std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
	std::cout << "double: " << number << ".0" << std::endl;
}

void toSpecialNumber(type currentType, std::string const &string)
{
	std::cout << "char: impossible to convert to char" << std::endl;
	std::cout << "int: impossible to convert to int" << std::endl;
	if (currentType == _float)
	{
		std::cout << "float: " << string << std::endl;
		std::cout << "double: " << string.substr(0, string.length() - 1) << std::endl;
	}
	else if (currentType == _double)
	{
		std::cout << "float: " << string << "f" << std::endl;
		std::cout << "double: " << string << std::endl;
	}
}

void	ScalarConverter::convert(std::string const &string)
{
	switch (getType(string))
	{
		case (_char):
			toChar(string[0]);
			break;

		case (_int):
			toInt(string, atoi(string.c_str()));
			break;

		case (_float):
			if (isSpecialNumber(string))
				toSpecialNumber(_float, string);
			else
				toFloat(string, atof(string.c_str()));
			break;

		case (_double):
			if (isSpecialNumber(string))
				toSpecialNumber(_double, string);
			else
				toDouble(string, std::strtod(string.c_str(), NULL));
			break;

		default:
			std::cout << "\e[31m[ERROR]\e[0m wrong type..." << std::endl;
			break;
	}
}
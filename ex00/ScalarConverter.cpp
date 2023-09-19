/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/19 16:46:50y elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits>
#include <stdlib.h>
#include <iomanip>
#include <cmath>
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
	size_t	i = 0;

	if (string[i] == '-')
		i++;
	if (string == "-inff" || string == "+inff" || string == "nanf")
		return (true);
	if (string[string.length() - 1] != 'f')
		return (false);
	for (; i < string.length() - 1; i++)
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
	size_t	i = 0;

	if (string[i] == '-')
		i++;
	if (string == "-inf" || string == "+inf" || string == "nan")
		return (true);
	for (; i < string.length(); i++)
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
	char	valueChar;
	int		valueInt;
	float	valueFloat;
	double	valueDouble;

	switch (getType(string))
	{
		case (_char): {
			valueChar = string[0];
			valueInt = static_cast<int>(valueChar);
			valueFloat = static_cast<float>(valueChar);
			valueDouble = static_cast<double>(valueChar);
		} break;

		case (_int): {
			long tmpLong = std::strtol(string.c_str(), NULL, 10);
			if (tmpLong > std::numeric_limits<int>::max() || tmpLong < std::numeric_limits<int>::min())
			{
				std::cout << "\e[31m[ERROR]\e[0m overflow on int..." << std::endl;
				return ;
			}
			valueInt = static_cast<int>(tmpLong);
			valueFloat = static_cast<float>(valueInt);
			valueDouble =  static_cast<double>(valueInt);
		} break;

		case (_float): {
			if (isSpecialNumber(string))
				toSpecialNumber(_float, string);
			else
			{
				valueFloat = std::strtof(string.c_str(), NULL);
				if (valueFloat == HUGE_VALF)
				{
					std::cout << "\e[31m[ERROR]\e[0m overflow on float..." << std::endl;
					return ;
				}
				valueInt = static_cast<int>(valueFloat);
				valueDouble = static_cast<double>(valueFloat);
			}
		} break;

		case (_double): {
			if (isSpecialNumber(string))
				toSpecialNumber(_double, string);
			else
			{
				valueDouble = std::strtod(string.c_str(), NULL);
				if (valueDouble == HUGE_VAL)
				{
					std::cout << "\e[31m[ERROR]\e[0m overflow on double..." << std::endl;
					return ;
				}
				valueInt = static_cast<int>(valueDouble);
				valueFloat = static_cast<float>(valueDouble);
			}
		} break;

		default: {
			std::cout << "\e[31m[ERROR]\e[0m wrong type..." << std::endl;
			return ;
		} break;
	}
	if (valueInt >= 32 && valueInt <= 126)
		std::cout << "char  : '" << static_cast<char>(valueInt) << "'" << std::endl;
	else
		std::cout << "char  : Non displayable char" << std::endl;
	if (valueFloat > std::numeric_limits<int>::max() || valueFloat < std::numeric_limits<int>::min())
		std::cout << "int   : overflow" << std::endl;
	else 
		std::cout << "int   : " << valueInt << std::endl;
	if (valueFloat == HUGE_VALF)
		std::cout << "float : overflow" << std::endl;
	else 
	{
		if (valueFloat - valueInt == 0)
			std::cout << "float : " << valueFloat << ".0f" << std::endl;
		else
			std::cout << "float : " << valueFloat << "f" << std::endl;
	}
	if (valueDouble - valueInt == 0)
		std::cout << "double: " << valueDouble << ".0" << std::endl;
	else
		std::cout << "double: " << valueDouble << std::endl;
}
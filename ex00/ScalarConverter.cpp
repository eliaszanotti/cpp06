/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/18 16:13:12 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits>
#include "ScalarConverter.hpp"

// Print
void ScalarConverter::print(std::string const &str, int color) const
{
	std::string colorsString = "";
	std::string reset = "\e[0m";
	
	if (color > 0 && color <= 9)
	{
		std::ostringstream oss;
		oss << "\e[3" << color << "m";
		colorsString = oss.str();
	}
	if (str.empty())
		std::cout << colorsString << "[ScalarConverter " << this->_string << "] " << reset;
	else
		std::cout << colorsString << "[ScalarConverter " << this->_string << "] " << reset << str << std::endl;
}

// utils
int ScalarConverter::_ft_stoi() const
{
	int number;
	std::stringstream	ss(this->_string);

	ss >> number;
    return (number);
}

float ScalarConverter::_ft_stof() const
{
	int number;
	std::stringstream	ss(this->_string);

	ss >> number;
    return (number);
}

double ScalarConverter::_ft_stod() const
{
	int number;
	std::stringstream	ss(this->_string);

	ss >> number;
    return (number);
}

// isType
bool ScalarConverter::_isChar() const
{
	if (this->_string.length() != 1)
		return (false);
	if (this->_string[0] < std::numeric_limits<char>::min() \
		|| this->_string[0] > std::numeric_limits<char>::max() \
		|| isdigit(this->_string[0]))
		return (false);
	return (true);
}

bool ScalarConverter::_isInt() const
{
	size_t	i = 0;

	if (this->_string[i] == '-')
		i++;
	for (; i < this->_string.length(); i++)	
	{
		if (!isdigit(this->_string[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::_isFloat() const
{
	bool	hasPoint = false;

	if (this->_string == "-inff" || this->_string == "+inff" || this->_string == "nanf")
		return (true);
	if (this->_string[this->_string.length() - 1] != 'f')
		return (false);
	for (size_t i = 0; i < this->_string.length() - 1; i++)
	{
		if (this->_string[i] == '.')
		{
			if (hasPoint)
				return (false);
			hasPoint = true;
		}
		else if (!isdigit(this->_string[i]))
			return (false);
	}
    return (true);
}

bool ScalarConverter::_isDouble() const
{
	bool	hasPoint = false;

	if (this->_string == "-inf" || this->_string == "+inf" || this->_string == "nan")
		return (true);
	for (size_t i = 0; i < this->_string.length(); i++)
	{
		if (this->_string[i] == '.')
		{
			if (hasPoint)
				return (false);
			hasPoint = true;
		}
		else if (!isdigit(this->_string[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::_isSpecialNumber() const
{
	if (this->_string == "-inff" || this->_string == "+inff" || this->_string == "nanf" || \
		this->_string == "-inf" || this->_string == "+inf" || this->_string == "nan")
		return (true);
	return (false);
}

// Getter	
type ScalarConverter::_getType() const
{
	if (this->_isChar())
		return (_char);
	if (this->_isInt())
		return (_int);
	if (this->_isFloat())
		return (_float);
	if (this->_isDouble())
		return (_double);
	return (_error);
}

// toType
void ScalarConverter::_toChar() const
{
	char c = this->_string[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::_toInt(int number) const
{
	if (isprint(number))
		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
	else	
		std::cout << "char: non printable char" << std::endl;
	std::cout << "int: " << number << std::endl;
	std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(number) << ".0" << std::endl;
}

void ScalarConverter::_toFloat(float number) const
{
	if (isprint(number))
		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
	else	
		std::cout << "char: non printable char" << std::endl;
	std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << "float: " << number << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(number) << ".0" << std::endl;
}

void ScalarConverter::_toDouble(double number) const
{
	if (isprint(number))
		std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
	else	
		std::cout << "char: non printable char" << std::endl;
	std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
	std::cout << "double: " << number << ".0" << std::endl;
}

void ScalarConverter::_toSpecialNumber(type currentType) const
{
	std::cout << "char: impossible to convert to char" << std::endl;
	std::cout << "int: impossible to convert to int" << std::endl;
	if (currentType == _float)
	{
		std::cout << "float: " << this->_string << std::endl;
		std::cout << "double: " << this->_string.substr(0, this->_string.length() - 1) << std::endl;
	}
	else if (currentType == _double)
	{
		std::cout << "float: " << this->_string << "f" << std::endl;
		std::cout << "double: " << this->_string << std::endl;
	}
}

// Constructors
ScalarConverter::ScalarConverter()
{
	this->_string = "0";
	this->print("created", 2);
}

ScalarConverter::ScalarConverter(std::string string)
{
	this->_string = string;
	this->print("created", 2);
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
	this->print("created by copy", 2);
}

ScalarConverter::~ScalarConverter()
{
	this->print("deleted", 1);
}

// Operators
ScalarConverter const	&ScalarConverter::operator=(ScalarConverter const &copy)
{
	this->_string = copy.getString();
	this->print("created by assignment", 2);
	return (*this);
}

// Getters and Setters
std::string ScalarConverter::getString(void) const
{
    return (this->_string);
}

//	Methods
void ScalarConverter::convert() const
{
	this->print("converting...", 3);
	switch (this->_getType())
	{
		case (_char):
			this->_toChar();
			break;

		case (_int):
			this->_toInt(this->_ft_stoi());
			break;

		case (_float):
			if (this->_isSpecialNumber())
				this->_toSpecialNumber(_float);
			else
				this->_toFloat(this->_ft_stof());
			break;

		case (_double):
			if (this->_isSpecialNumber())
				this->_toSpecialNumber(_double);
			else
				this->_toDouble(this->_ft_stod());
			break;

		default:
			std::cout << "\e[31m[ERROR]\e[0m wrong type..." << std::endl;
			break;
	}
	this->print("converted", 3);
}
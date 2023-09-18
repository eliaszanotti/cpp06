/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/18 15:23:59 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
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

// Methods
bool ScalarConverter::_isChar() const
{
	if (this->_string.length() != 1)
		return (false);
	if (!std::isprint(this->_string[0]))
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
		if (this->_string[i] == '.' && hasPoint)
		{
			if (hasPoint)
				return (false);
			hasPoint = true;
		}
		if (!isdigit(this->_string[i]))
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
		if (this->_string[i] == '.' && hasPoint)
		{
			if (hasPoint)
				return (false);
			hasPoint = true;
		}
		if (!isdigit(this->_string[i]))
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

void ScalarConverter::_toChar() const
{
	char c = this->_string[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "int: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "int: " << static_cast<double>(c) << ".0" << std::endl;
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
		
			
	}


	this->print("converted", 3);
}
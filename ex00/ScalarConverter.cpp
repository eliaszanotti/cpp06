/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/18 13:45:35 by elias            ###   ########.fr       */
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
	this->print("converting", 3);
}
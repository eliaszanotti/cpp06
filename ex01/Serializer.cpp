/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/20 14:13:45 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stdint.h>
#include "Serializer.hpp"

// Print
void Serializer::print(std::string const &str, int color) const
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
		std::cout << colorsString << "[Serializer] " << reset;
	else
		std::cout << colorsString << "[Serializer] " << reset << str << std::endl;
}

// Constructors
Serializer::Serializer()
{
	this->print("created", 2);
}

Serializer::Serializer(Serializer const &copy)
{
	*this = copy;
	this->print("created by copy", 2);
}

Serializer::~Serializer()
{
	this->print("deleted", 1);
}

// Operators
Serializer const	&Serializer::operator=(Serializer const &copy)
{
	(void)copy;
	this->print("created by assignment", 2);
	return (*this);
}

// Methods
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
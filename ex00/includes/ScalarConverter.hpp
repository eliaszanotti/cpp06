/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/18 15:23:33 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_H
# define SCALARCONVERTER_CLASS_H

# include <iostream>

enum type {
    _specialNumber,
    _char,
    _int,
    _float,
    _double,
    _error
};

class ScalarConverter
{
	private:
		std::string _string;
		// Print
		void	print(std::string const &str, int color) const;
		//   isType
		bool	_isChar() const;
		bool	_isInt() const;
		bool	_isFloat() const;
		bool	_isDouble() const;
		bool	_isSpecialNumber() const;
		// Getter
		type	_getType() const;
		// toType
		void	_toChar() const;
		void	_toInt() const;
		void	_toFloat() const;
		void	_toDouble() const;
		void	_toSpecialNumber() const;

	public:
		// Constructors
		ScalarConverter();
		ScalarConverter(std::string string);
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter();

		// Operators
		ScalarConverter const	&operator=(ScalarConverter const &copy);

		// Getters and Setters
		std::string	getString(void) const;

		// Methods
		void	convert() const;
};

#endif
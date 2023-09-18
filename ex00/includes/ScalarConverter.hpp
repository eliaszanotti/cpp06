/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/18 13:44:33 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_H
# define SCALARCONVERTER_CLASS_H

# include <iostream>

class ScalarConverter
{
	private:
		std::string _string;
		// Print
		void	print(std::string const &str, int color) const;

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
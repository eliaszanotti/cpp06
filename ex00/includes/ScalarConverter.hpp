/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/19 16:37:46 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_H
# define SCALARCONVERTER_CLASS_H

# include <iostream>

enum type {
    _char,
    _int,
    _float,
    _double,
    _error
};

class ScalarConverter
{
	public:
		static void	convert(std::string const &string);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/20 14:14:01 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_H
# define SERIALIZER_CLASS_H

# include <stdint.h>
# include <iostream>

struct Data
{
    int		dataInt;
    char	dataChar;
    double	dataDouble;
};

class Serializer
{
	private:
		// Print
		void	print(std::string const &str, int color) const;

	public:
		// Constructors
		Serializer();
		Serializer(Serializer const &copy);
		~Serializer();

		// Operators
		Serializer const	&operator=(Serializer const &copy);

		// Methods
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
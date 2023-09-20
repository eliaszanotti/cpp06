/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/20 15:16:07 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_H
# define BASE_CLASS_H

# include <iostream>

class Base
{
	public:
		virtual ~Base();
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base    *generate(void);
void    identify(Base *p);
void    identify(Base &p);

#endif
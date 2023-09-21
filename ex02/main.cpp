/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:13:54 by elias             #+#    #+#             */
/*   Updated: 2023/09/21 14:28:56 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"

int main()
{
    Base    *randomBase = generate();
    identify(randomBase);
    identify(*randomBase);
    delete (randomBase);
}
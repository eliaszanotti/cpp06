/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:53:31 by elias             #+#    #+#             */
/*   Updated: 2023/09/20 15:23:06 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Base.hpp"

Base    *generate(void)
{
    srand (time(NULL));

    int randomInt;
    randomInt = rand() % 3;
    switch (randomInt)
    {
        case (0): {
            std::cout << "\e[33m[Base random creation]\e[0m A" << std::endl;   
            return (new A);
        }
        
        case (1): {
            std::cout << "\e[33m[Base random creation]\e[0m B" << std::endl;   
            return (new B);
        }

        case (2): {
            std::cout << "\e[33m[Base random creation]\e[0m C" << std::endl;   
            return (new C);
        }
    }    
    return (NULL);
}

void    identify(Base *p)
{
    try
    {
        if (dynamic_cast<A *>(p))
            std::cout << "\e[32m[Base type is]\e[0m A" << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        if (dynamic_cast<B *>(p))
            std::cout << "\e[32m[Base type is]\e[0m B" << std::endl;
    }
    catch(const std::exception& e) {}
    try
    {
        if (dynamic_cast<C *>(p))
            std::cout << "\e[32m[Base type is]\e[0m C" << std::endl;
    }
    catch(const std::exception& e) {}
}

void    identify(Base &p)
{
    if (dynamic_cast<A *>(&p))
        std::cout << "\e[32m[Base type is]\e[0m A" << std::endl;
    if (dynamic_cast<B *>(&p))
        std::cout << "\e[32m[Base type is]\e[0m B" << std::endl;
    if (dynamic_cast<C *>(&p))
        std::cout << "\e[32m[Base type is]\e[0m C" << std::endl;
}
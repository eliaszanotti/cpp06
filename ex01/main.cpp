/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:18:33 by elias             #+#    #+#             */
/*   Updated: 2023/09/20 14:15:24 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data    firstData;
    firstData.dataInt = 42;
    firstData.dataChar = 'e';
    firstData.dataDouble = 0.9;

    uintptr_t   ptr = Serializer::serialize(&firstData);
    Data        *newData = Serializer::deserialize(ptr);
    
    if (&firstData == newData)
    {
        std::cout << "\e[33m[firstData]\e[0m " << &firstData << " | int: " << firstData.dataInt << std::endl;
        std::cout << "\e[33m[newData  ]\e[0m " << newData << " | int: " << newData->dataInt << std::endl;
    }
    else
        std::cout << "\e[31m[ERROR]\e[0m Failed to serialize" << std::endl;
    return (0);
}
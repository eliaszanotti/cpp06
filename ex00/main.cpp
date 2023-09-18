/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:38:26 by elias             #+#    #+#             */
/*   Updated: 2023/09/18 13:46:25 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2 || !*argv[0])
    {
        std::cout << "\e[31m[ERROR]\e[0m Usage: ./convert <literal>" << std::endl;
        return (1);
    }
    return (0);
}
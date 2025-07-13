/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:17:59 by asayad            #+#    #+#             */
/*   Updated: 2025/07/13 18:26:56 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int main(int ac, char** av){
    if (ac == 2){
        try{
            RPN a;
            a.fillInput(static_cast<std::string>(av[1]));
            std::cout << a.calculate() << '\n';
        }catch (const std::exception& e){
            std::cout << e.what() << '\n';
        }
    } else  
        std::cout << "Too many/Few arguments !" << '\n';
}
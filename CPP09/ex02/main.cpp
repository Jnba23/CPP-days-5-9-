/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:02:04 by asayad            #+#    #+#             */
/*   Updated: 2025/07/16 10:39:31 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int main(int ac, char** av){
    if (ac != 1){
        try{
            PmergeMe o;
            o.parseInput(ac, av);
            o.FillVecs(ac, av);
            o.sort(o.mainInit);
        } catch (const std::exception& e){
            std::cout << e.what() << '\n';
        }
    } else
        std::cout << "Not enough args !" << '\n';
    return (0);
}
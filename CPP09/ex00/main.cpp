/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:19:47 by asayad            #+#    #+#             */
/*   Updated: 2025/07/12 11:50:57 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int main(int ac, char** av){
    if (ac == 2){
        try{
            BitcoinEx db;
            db.fillData();
            std::fstream in(av[1]);
            if (!in)
                throw(std::runtime_error("Invalid input file !"));
            search(db, in);
        }catch (const std::exception& e){
            std::cout << e.what() << '\n';
        }
    } else
        std::cout << "Insufficient or too many args !" << '\n';
}
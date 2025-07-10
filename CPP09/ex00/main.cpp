/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:19:47 by asayad            #+#    #+#             */
/*   Updated: 2025/07/10 18:30:52 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

int main(int ac, char** av){
    if (ac == 2){
        (void)av;
        BitcoinEx db;
        db.fillData();
        std::fstream in(av[1]);
        if (!in)
            return (std::cout << "Invalid file !" << '\n', 0);
        search(db, in);
    }
}
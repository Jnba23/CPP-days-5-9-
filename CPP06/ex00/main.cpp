/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:48:03 by asayad            #+#    #+#             */
/*   Updated: 2025/06/18 12:53:30 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>

int main(int ac, char **av){
    if (ac == 2){
        std::string m;
        std::istringstream s(av[1]);
        if (s >> m && (s >> std::ws, s.eof())){
          try {
            ScalarConverter::convert(m);
          } catch (const std::exception& c){
              std::cout << c.what() << '\n';
          } 
        } else {
            std::cout << "invalid input !" << '\n';
            return (0);
        }
    } else
        std::cout << "too many/few args !" << '\n';
    return (0);
}
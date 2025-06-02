/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:43:39 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 16:44:42 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

int main(){
    try{
        Bureaucrat c("Pepe", 1);
        Bureaucrat l("Meme", 150);
        std::cout << c;
        for (int i = 0; i < 7; i++){
            l.decrementGrd();
        }
        for (int i = 0; i < 7; i++){
            c.incrementGrd();
        }
    }
    catch (const std::exception& c){
        std::cout << "Exception caught : " << c.what() << '\n';
    }
}
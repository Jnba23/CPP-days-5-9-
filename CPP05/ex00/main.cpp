/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:43:39 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 21:12:04 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

int main(){
    try{
        Bureaucrat c("Pepe", 1);
        Bureaucrat l("Meme", 150);
        std::cout << c;
        try {
            for (int i = 0; i < 7; i++){
                l.decrementGrd();
                std::cout << "Bureaucrat's grade is : " << l.getGrade() << '\n';
            }
            for (int i = 0; i < 7; i++){
                c.incrementGrd();
                std::cout << "Bureaucrat's grade is : " << l.getGrade() << '\n';
            }
        } catch(const std::exception& c){
            std::cout << c.what() << '\n';
        }
    }
    catch (const std::exception& c){
        std::cout << "Exception caught : " << c.what() << '\n';
    }
}
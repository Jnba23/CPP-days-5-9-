/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:43:39 by asayad            #+#    #+#             */
/*   Updated: 2025/05/21 12:19:56 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

int main(){
    try{
        Bureaucrat c("Pepe", 150);
        std::cout << c;
        for (int i = 0; i < 7; i++){
            c.decrementGrd();
        }
    }
    catch (Bureaucrat::GradeTooHigh& c){
        std::cout << "Exception caught : " << c.what() << '\n';
    }
    catch (Bureaucrat::GradeTooLow& c){
        std::cout << "Exception caught : " << c.what() << '\n';
    }
}
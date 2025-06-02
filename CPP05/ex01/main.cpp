/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:43:39 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 17:37:36 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bureaucrat.hpp>

int main(){
    try{
        Bureaucrat c("Pepe", 1);
        Bureaucrat p("Meme", 10);
        Form d("Certif", 10, 130);
        Form m("Attestation", 8, 3);
        std::cout << c;
        std::cout << p;
        std::cout << d;
        std::cout << m;
        try{
            p.signForm(d);
        } catch (const std::exception& c){
            std::cout << c.what();
        }
        try{
            p.signForm(m);
        } catch (const std::exception& c){
            std::cout << c.what();
        }
        try{
            p.signForm(m);
        } catch (const std::exception& c){
            std::cout << c.what();
        }
    }
    catch (const std::exception& c) {
        std::cout << "Exception caught : " << c.what() << '\n';
    }
}
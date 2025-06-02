/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:35:45 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 19:32:56 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>




int main(){
    try{
        Bureaucrat b("Bob", 15);
        PresidentialPardonForm p("USA");
        ShrubberyCreationForm s("Garden");
        RobotomyRequestForm r("Hamza");
        try{
            b.signForm(p);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.executeForm(p);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.signForm(s);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.signForm(r);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.executeForm(s);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.executeForm(r);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
    } catch(std::exception& c){
        std::cout << c.what() << '\n';
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:35:45 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 21:23:07 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Intern.hpp>

int main(){
    try{
        Bureaucrat b("Bob", 140);
        Intern i1;
        AForm* f1 = i1.makeForm("Presidential Pardon", "Russia");
        AForm* f2 = i1.makeForm("Shrubbery creation", "Field");
        AForm* f3 = i1.makeForm("Robotomy Request", "Brother");
        try{
            b.signForm(*f1);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.executeForm(*f1);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.signForm(*f2);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.executeForm(*f2);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.signForm(*f3);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.executeForm(*f3);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        try{
            b.executeForm(*f3);
        }catch (const std::exception& c){
            std::cout << c.what() << '\n';
        }
        delete f1;
        delete f2;
        delete f3;
    } catch(std::exception& c) {
        std::cout << c.what() << '\n';
    }
}
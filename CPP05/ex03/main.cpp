/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:35:45 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 19:46:37 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Intern.hpp>

int main(){
    AForm* f1;
    AForm* f2;
    AForm* f3;

    try{
        Bureaucrat b("Bob", 5);
        Intern i1;
        f1 = i1.makeForm("Presidential Pardon", "Russia");
        f2 = i1.makeForm("Shrubbery creation", "Field");
        f3 = i1.makeForm("Robotomy Request", "Brother");
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
    } catch(std::exception& c) {
        std::cout << c.what() << '\n';
    }
    delete f1;
    delete f2;
    delete f3;
}
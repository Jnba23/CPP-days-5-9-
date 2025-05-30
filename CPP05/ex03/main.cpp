/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:35:45 by asayad            #+#    #+#             */
/*   Updated: 2025/05/30 18:11:55 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

int main(){
    try{
        Bureaucrat b("Bob", 43);
        PresidentialPardonForm p("Bob");
        ShrubberyCreationForm s("Bob");
        RobotomyRequestForm r("Bob");
        RobotomyRequestForm r1("Bob");
        RobotomyRequestForm r2("Bob");
        RobotomyRequestForm r3("Bob");
        b.signForm(p);
        b.signForm(s);
        b.signForm(r);
        b.signForm(r1);
        b.signForm(r2);
        b.signForm(r3);
        b.executeForm(p);
        b.executeForm(r2);
        b.executeForm(s);
    } catch(std::exception& c){
        std::cout << c.what() << '\n';
    }
}
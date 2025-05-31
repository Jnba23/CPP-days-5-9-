/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:02:39 by asayad            #+#    #+#             */
/*   Updated: 2025/05/31 18:24:13 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>

Intern::Intern(){
    std::cout << "Intern constructor called !" << '\n';
}

Intern::Intern(const Intern& i){
    std::cout << "Intern copy constructor called !" << '\n';
}

const Intern& Intern::operator=(const Intern& i){
    std::cout << "Intern assignment operator called !" << '\n';
    return (*this);
}

Intern::~Intern(){
    std::cout << "Intern destructor called !" << '\n';
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target){
    
    FORMTYPE a;
    
    AForm*   n;
    switch (a){
        case PRESIDENTIALPARDONFORM :
            n = new PresidentialPardonForm(target);
            break ;
        case SHRUBBERYCREATIONFORM :
            n = new ShrubberyCreationForm(target);
            break ;
        case ROBOTOMYREQUESTFORM :
            n = new RobotomyRequestForm(target);
            break ;
        }
        
}
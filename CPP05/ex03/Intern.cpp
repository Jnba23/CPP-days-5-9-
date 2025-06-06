/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:02:39 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 19:42:46 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>

Intern::Intern(){
}

Intern::Intern(const Intern& i){
    *this = i;
}

const Intern& Intern::operator=(const Intern& i){
    (void)i;
    return (*this);
}

Intern::~Intern(){
}

AForm* Intern::PPform(const std::string& target){
    return (new PresidentialPardonForm(target));
}

AForm* Intern::RRform(const std::string& target){
    return (new RobotomyRequestForm(target));
}

AForm* Intern::SCform(const std::string& target){
    return (new ShrubberyCreationForm(target));
}

const char* InvalidFrom::what() const throw(){
    return ("Invalid Form !");
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target){
    std::string formLow = formName;
    static const Form table[3] = {{&PPform, "presidential pardon"}, 
                    {&RRform, "robotomy request"},
                    {&SCform, "shrubbery creation"}
                };
    for(size_t i = 0; i < formLow.size(); i++)
        formLow[i] = std::tolower(formLow[i]);
    for(size_t i = 0; i < 3; i++){
        if (formLow == table[i].name){
            std::cout << "Intern creates " << formName << '\n';
            return (table[i].formFunc(target));
        }
    }
    throw (InvalidFrom());
    return (NULL);
}
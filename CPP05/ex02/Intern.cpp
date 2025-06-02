/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:02:39 by asayad            #+#    #+#             */
/*   Updated: 2025/06/01 12:14:30 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>

Intern::Intern(){
    std::cout << "Intern constructor called !" << '\n';
}

Intern::Intern(const Intern& i){
    std::cout << "Intern copy constructor called !" << '\n';
    *this = i;
}

const Intern& Intern::operator=(const Intern& i){
    std::cout << "Intern assignment operator called !" << '\n';
    (void)i;
    return (*this);
}

Intern::~Intern(){
    std::cout << "Intern destructor called !" << '\n';
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
    static const Form table[3] = {{&PPform, "presidentialpardonform"}, 
                    {&RRform, "robotomyrequestform"},
                    {&SCform, "shrubberycreationform"}
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
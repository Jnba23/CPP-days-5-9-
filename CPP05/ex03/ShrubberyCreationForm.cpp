/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 07:39:52 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 17:12:45 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& tar) : AForm("ShrubberyCreationForm", 145, 137){
    // std::cout << "Shrub constructor called !" << '\n';
    target = tar;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s) : AForm(s.getFormName(),
                    s.getSignGrd(), s.getExecGrd()){
    // std::cout << "Shrub copy constructor called !" << '\n';
    *this = s; 
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s){
    // std::cout << "Shrub assignment operator called !" << '\n';
    if (this != &s){
        setFsigned(s.fsigned());
        target = s.target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    // std::cout << "Shrub destructor called !" << '\n';
}

const std::string& ShrubberyCreationForm::getTarget() const{
    return (target);
}

void ShrubberyCreationForm::executef() const{
    std::ofstream f((getTarget() + "_shrubbery").c_str());
    if (!f.is_open())
        throw (FileOpeningException());
    f << "        /\\\n"
    << "       /  \\\n"
    << "      /    \\\n"
    << "     /______\\\n"
    << "       ||||\n"
    << "       ||||\n"
    << "    ~~Shrubbery~~\n" << '\n';
    f.close ();
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 08:48:21 by asayad            #+#    #+#             */
/*   Updated: 2025/05/30 16:31:58 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(const std::string& name): AForm(name, 72, 45){
    std::cout << "Robot constructor called !" << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : 
            AForm(s.getFormName(), s.getSignGrd(), s.getExecGrd()){
    std::cout << "Robot copy constructor called !" << '\n';
    *this = s;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& r){
    std::cout << "Robot assignment operator called !" << '\n';
    if (this != &r){
        setFsigned(r.fsigned());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Robot destructor called !" << '\n';
}

void RobotomyRequestForm::executef() const{
    std::cout << "Drilling noises *!*!*!..." << '\n';
    if (i % 2 != 0)
        std::cout << getFormName() << " has been robotomized !" << '\n';
    else
        std::cout << getFormName() << " robotomy failed !" << '\n';
    i++;
}
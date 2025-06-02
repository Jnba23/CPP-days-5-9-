/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 08:48:21 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 19:29:08 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(const std::string& tar): AForm("RobotomyRequest", 72, 45){
    // std::cout << "Robot constructor called !" << '\n';
    target = tar;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : 
            AForm(s.getFormName(), s.getSignGrd(), s.getExecGrd()){
    // std::cout << "Robot copy constructor called !" << '\n';
    *this = s;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& r){
    // std::cout << "Robot assignment operator called !" << '\n';
    if (this != &r){
        setFsigned(r.fsigned());
        target = r.target;
    }
    return (*this);
}

const std::string& RobotomyRequestForm::getTarget() const{
    return (target);
}

RobotomyRequestForm::~RobotomyRequestForm(){
    // std::cout << "Robot destructor called !" << '\n';
}

void RobotomyRequestForm::executef() const{
    static unsigned int i(time(0) %  0x7fffffff);

    std::cout << "Drilling noises *!*!*!..." << '\n';
    if (i % 2 != 0)
        std::cout << getTarget() << " has been robotomized !" << '\n';
    else
        std::cout << getTarget() << " robotomy failed !" << '\n';
    i++;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 08:48:21 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 22:01:49 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>

RobotomyRequestForm::RobotomyRequestForm(const std::string& tar): AForm("RobotomyRequest", 72, 45){
    target = tar;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s) : 
            AForm(s.getFormName(), s.getSignGrd(), s.getExecGrd()){
    *this = s;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& r){
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
}

void RobotomyRequestForm::executef() const{
    static unsigned int i(time(0));
    std::cout << "Drilling noises *!*!*!..." << '\n';
    if (i % 2 != 0)
        std::cout << getTarget() << " has been robotomized !" << '\n';
    else
        std::cout << getTarget() << " robotomy failed !" << '\n';
    i++;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:04:06 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 19:39:09 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(const std::string& tar): AForm("PresidentialPardonForm", 25, 5){

    target = tar;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p): 
                    AForm(p.getFormName(), p.getSignGrd(), p.getExecGrd()){
    *this = p;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p){
    if (this != &p){
        setFsigned(p.fsigned());
        target = p.target;
    }
    return (*this);
}

const std::string& PresidentialPardonForm::getTarget() const{
    return (target);
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void PresidentialPardonForm::executef() const{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox " << '\n';
}
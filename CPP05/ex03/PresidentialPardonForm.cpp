/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:04:06 by asayad            #+#    #+#             */
/*   Updated: 2025/05/30 16:28:22 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>

PresidentialPardonForm::PresidentialPardonForm(const std::string& name): AForm(name, 25, 5){
    std::cout << "Presidential constructor called !" << '\n';
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& p): 
                    AForm(p.getFormName(), p.getSignGrd(), p.getExecGrd()){
    std::cout << "Presidential copy constructor called !" << '\n';
    *this = p;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& p){
    std::cout << "Presidential assignment operator called !" << '\n';
    if (this != &p){
        setFsigned(p.fsigned());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Presidential destructor called !" << '\n';
}

void PresidentialPardonForm::executef() const{
    std::cout << getFormName() << " has been pardoned by Zaphod Beeblebrox " << '\n';
}
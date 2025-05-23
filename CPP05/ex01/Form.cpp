/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:22:17 by asayad            #+#    #+#             */
/*   Updated: 2025/05/21 13:42:16 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <./incs/Form.hpp>

Form::Form(std::string n, int sign_grd, int exec_grd): name(n), signature_grade(sign_grd), exec_grade(exec_grd), formSigned(false){
    std::cout << "Form constructor called !" << '\n';
}

Form::Form(const Form& f){
   std::cout << "Form constructor called !" << '\n'; 
}

Form& Form::operator=(const Form& f){
    return (*this);
}

const std::string& Form::getFormName(){
    return (name);
}

const int Form::getSignGrd(){
    return (signature_grade);
}

const int Form::getExecGrd(){
    return (exec_grade);
}

bool Form::fsigned(){
    return (formSigned);
}

void Form::beSigned(const Bureaucrat& b){
    if (b.getGrade() <= getSignGrd())
}

Form::~Form(){
    std::cout << "Form destructor called !" << '\n';
}
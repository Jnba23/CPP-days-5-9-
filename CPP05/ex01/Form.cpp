/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:22:17 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 17:35:47 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Form.hpp>

Form::Form(): name("DefForm"), formSigned(false), signature_grade(10), exec_grade(10){
    // std::cout << "Form constructor called !" << '\n';
}

Form::Form(std::string n, int sign_grd, int exec_grd): name(n), formSigned(false), signature_grade(sign_grd), exec_grade(exec_grd){
    if (signature_grade > 150 || exec_grade > 150)
        throw (GradeTooLowException());
    else if (signature_grade < 1 || exec_grade < 1)
        throw (GradeTooHighException());
    // std::cout << "Form constructor called !" << '\n';
}

Form::Form(const Form& f): name(f.name), formSigned(f.formSigned), signature_grade(f.signature_grade), exec_grade(f.exec_grade){
//    std::cout << "Form copy constructor called !" << '\n';
   *this = f;
}

Form& Form::operator=(const Form& f){
    if (this != &f)
        formSigned = f.formSigned;
    return (*this);
}

const std::string& Form::getFormName() const{
    return (name);
}

int Form::getSignGrd() const{
    return (signature_grade);
}

int Form::getExecGrd() const{
    return (exec_grade);
}

bool Form::fsigned() const{
    return (formSigned);
}

void Form::beSigned(const Bureaucrat& b){
    if (b.getGrade() > getSignGrd()){
        throw(Bureaucrat::GradeTooLowException());
    }
    if (fsigned())
        throw (FormSigned());
    formSigned = true;
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Form's Signature/Execution grade too low !");
    
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Form's Signature/Execution grade too high !");
    
}

const char* Form::FormSigned::what() const throw(){
    return ("Form's signed Already !\n");
    
}

std::ostream& operator<<(std::ostream& out, const Form& f){
    out << "Form name : " << f.getFormName() << ", Form signature grade : " << f.getSignGrd()
        << ", Form execution grade : " << f.getExecGrd() << '\n';
    return (out);
}

Form::~Form(){
    // std::cout << "Form destructor called !" << '\n';
}
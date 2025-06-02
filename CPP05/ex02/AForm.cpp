/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:49:50 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 19:36:01 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <AForm.hpp>


AForm::AForm(std::string n, int sign_grd, int exec_grd) : name(n), formSigned(false),
                signature_grade(sign_grd), exec_grade(exec_grd){
    // std::cout << "Base constructor called !" << '\n';
}

AForm::AForm(const AForm& f): name(f.name), formSigned(f.formSigned),
                signature_grade(f.signature_grade), exec_grade(f.exec_grade){
    // std::cout << "Base copy constructor called !" << '\n';
    formSigned = f.formSigned;
}

AForm::~AForm(){
    // std::cout << "Base destructor called !" << '\n';
}

const std::string& AForm::getFormName() const{
    return (name);
}

int AForm::getSignGrd() const{
    return (signature_grade);
}

int AForm::getExecGrd() const{
    return (exec_grade);
}

bool AForm::fsigned() const{
    return (formSigned);
}

void AForm::setFsigned(bool a){
    formSigned = a;
}

void AForm::beSigned(const Bureaucrat& b){
    if (b.getGrade() > getSignGrd()){
        throw(Bureaucrat::GradeTooLowException());
    }
    if (fsigned())
        throw (FormSignedException());
    formSigned = true;
}

const char* AForm::FormSignedException::what() const throw() {
    return ("Form's signed already !");
}

const char* AForm::FormUnsignedException::what() const throw() {
    return ("The form needs to be signed first !");
}

const char* AForm::FileOpeningException::what() const throw() {
    return ("Shruberry : File openning failed !");
}

void AForm::execute(Bureaucrat const& executor) const{
    if (executor.getGrade() > getSignGrd())
        throw (Bureaucrat::GradeTooLowException());
    else if (!fsigned())
        throw (FormUnsignedException());
    executef();
}

std::ostream& operator<<(std::ostream& out, const AForm& f){
    out << "Form name : " << f.getFormName() << ", Form signature grade : " << f.getSignGrd()
        << ", Form execution grade : " << f.getExecGrd() << '\n';
    return (out);
}

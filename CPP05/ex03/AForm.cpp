/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:49:50 by asayad            #+#    #+#             */
/*   Updated: 2025/05/30 18:10:35 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>

int AForm::i;
AForm::AForm(std::string n, int sign_grd, int exec_grd) : name(n), formSigned(false),
                signature_grade(sign_grd), exec_grade(exec_grd){
    std::cout << "Base constructor called !" << '\n';
}

AForm::AForm(const AForm& f): name(f.name), formSigned(f.formSigned),
                signature_grade(f.signature_grade), exec_grade(f.exec_grade){
    std::cout << "Base copy constructor called !" << '\n';
    formSigned = f.formSigned;
}

AForm::~AForm(){
    std::cout << "Base destructor called !" << '\n';
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

bool AForm::beSigned(const Bureaucrat& b){
    if (b.getGrade() > getSignGrd()){
        std::cout << b.getName() << " couldn't sign " << getFormName() << " because he's underranked !" << '\n';
        throw(GradeTooLowException());
    }
    formSigned = true;
    return (formSigned);
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("Form: bureaucrat's grade too low !");
}

const char* AForm::FormSignedException::what() const throw(){
    return ("Form: The form needs to be signed first !");
}

const char* AForm::FileOpeningException::what() const throw(){
    return ("Shruberry : File openning failed !");
}

void AForm::execute(Bureaucrat const& executor) const{
    if (executor.getGrade() > getSignGrd())
        throw (GradeTooLowException());
    else if (!fsigned())
        throw (FormSignedException());
    executef();
}

std::ostream& operator<<(std::ostream& out, const AForm& f){
    out << "Form name : " << f.getFormName() << ", Form signature grade : " << f.getSignGrd()
        << ", Form execution grade : " << f.getExecGrd() << '\n';
    return (out);
}
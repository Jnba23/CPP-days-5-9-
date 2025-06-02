/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:19:06 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 16:49:43 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(): name("DefBureaucrat"), grade(10){
    // std::cout << "Bureaucrat constructor called !" << '\n';
}

Bureaucrat::Bureaucrat(std::string name, int gd): name(name), grade(gd){
    if (grade < 1)
        throw (GradeTooHighException());
    else if (grade > 150)
        throw (GradeTooLowException());
    // std::cout << "Bureaucrat constructor called !" << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& b){
    (void)b;
    // std::cout << "Bureaucrat copy constructor called !" << '\n';
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b){
    (void)b;
    // std::cout << "Bureaucrat assignment operator called !" << '\n';
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b){
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << '\n';
    return out;
}

const std::string& Bureaucrat::getName() const{
    return (name);
}

int Bureaucrat::getGrade() const{
    return (grade);
}

void Bureaucrat::incrementGrd(){
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade -= 1;
}

void Bureaucrat::decrementGrd(){
    if (grade + 1 > 150){
        throw GradeTooLowException();
    }
    grade += 1;
}

void Bureaucrat::signForm(AForm& f){
    try{
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getFormName() << '\n';
    } catch (const std::exception& c){
        std::cout << getName() << " couldn't sign " << f.getFormName() << " because " << c.what() << '\n';
        throw ;
    }
}

void Bureaucrat::executeForm(AForm const& form){
    try{
        form.execute(*this);
        std::cout << getName() << " executed " << form.getFormName() << '\n';
    }
    catch (const std::exception& c){
        std::cout << c.what() << '\n';
    }
}

Bureaucrat::~Bureaucrat(){
    // std::cout << "Bureaucrat destructor called !" << '\n';
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Bureaucrat's Grade too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Bureaucrat's Grade too low !");
}
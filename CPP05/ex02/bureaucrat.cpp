/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:19:06 by asayad            #+#    #+#             */
/*   Updated: 2025/05/24 12:20:08 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bureaucrat.hpp>

Bureaucrat::Bureaucrat(std::string name, int gd): name(name), grade(gd){
    if (grade < 1)
        throw (GradeTooHigh());
    else if (grade > 150)
        throw (GradeTooLow());
    std::cout << "Bureaucrat constructor called !" << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& b){
    (void)b;
    std::cout << "Bureaucrat copy constructor called !" << '\n';
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b){
    (void)b;
    std::cout << "Bureaucrat assignment operator called !" << '\n';
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
    if (--grade < 1)
        throw GradeTooHigh();
    grade -= 1;
}

void Bureaucrat::decrementGrd(){
    if (++grade > 150){
        throw GradeTooLow();
    }
    grade += 1;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called !" << '\n';
}

void Bureaucrat::signForm(Form& f){
    if (f.beSigned(*this))
        std::cout << getName() << " signed " << f.getFormName() << '\n';
}

const char* GradeTooHigh::what() const throw(){
    return ("Grade too high !");
};

const char* GradeTooLow::what() const throw(){
    return ("Grade too low !");
};
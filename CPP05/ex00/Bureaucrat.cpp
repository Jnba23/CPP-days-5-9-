/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:19:06 by asayad            #+#    #+#             */
/*   Updated: 2025/05/24 09:08:51 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>

Bureaucrat::Bureaucrat(std::string name, int gd): name(name), grade(gd){
    Bureaucrat::GradeTooHigh c;
    Bureaucrat::GradeTooLow d;
    if (grade < 1)
        throw c;
    else if (grade > 150)
        throw d;
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
    if (--grade < 1){
        Bureaucrat::GradeTooHigh c;
        throw c;
    }
    grade -= 1;
}

void Bureaucrat::decrementGrd(){
    if (++grade > 150){
        Bureaucrat::GradeTooLow c;
        throw c;
    }
    grade += 1;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called !" << '\n';
}

const char* Bureaucrat::GradeTooHigh::what() const throw(){
    return ("Grade too high !");
};

const char* Bureaucrat::GradeTooLow::what() const throw(){
    return ("Grade too low !");
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:19:24 by asayad            #+#    #+#             */
/*   Updated: 2025/05/21 13:44:47 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <iostream>

class Form;
class Bureaucrat : public GradeTooHigh, public GradeTooLow{
    private:
        const std::string name;
        int grade;
    public:
    // form 
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat& operator=(const Bureaucrat& b);
        ~Bureaucrat();
        
        // methods
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrd();
        void decrementGrd();
        void signForm(const Form& f);
        
        // exept
    };
class GradeTooHigh : public std::exception{
    public:
    const char* what();
};
class GradeTooLow : public std::exception{
    public:
    const char* what();
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& c);

#endif
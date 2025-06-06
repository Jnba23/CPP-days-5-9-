/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:19:24 by asayad            #+#    #+#             */
/*   Updated: 2025/06/01 20:15:17 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <iostream>
#include <Form.hpp>

class Form;
class Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& b);
        Bureaucrat& operator=(const Bureaucrat& b);
        ~Bureaucrat();
        
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrd();
        void decrementGrd();
        void signForm(Form& f);
        class GradeTooHighException : public std::exception{
            public:
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
            const char* what() const throw();
        };
    };
std::ostream& operator<<(std::ostream& out, const Bureaucrat& c);

#endif
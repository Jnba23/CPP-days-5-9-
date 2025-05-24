/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:37:51 by asayad            #+#    #+#             */
/*   Updated: 2025/05/24 19:03:10 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <Bureaucrat.hpp>

class Bureaucrat;
class AForm{
    private:
        const std::string name;
        bool formSigned;
        const int signature_grade;
        const int exec_grade;
    public:
        public:
        AForm(std::string name, int sign_grd, int exec_grd);
        AForm(const AForm& f);
        AForm& operator=(const AForm& f);
        virtual ~AForm();
        virtual const std::string& getAFormName() const = 0;
        virtual int getSignGrd() const = 0;
        virtual int getExecGrd() const = 0;
        virtual bool fsigned() const = 0;
        virtual bool beSigned(const Bureaucrat& b) = 0;
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:23:09 by asayad            #+#    #+#             */
/*   Updated: 2025/05/30 08:05:10 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <bureaucrat.hpp>
class GradeTooHigh;
class GradeTppLow;

class Bureaucrat;
class Form{
    private:
        const std::string name;
        bool formSigned;
        const int signature_grade;
        const int exec_grade;
    public:
        Form(std::string name, int sign_grd, int exec_grd);
        Form(const Form& f);
        Form& operator=(const Form& f);
        ~Form();
        const std::string& getFormName() const;
        int getSignGrd() const;
        int getExecGrd() const;
        bool beSigned(const Bureaucrat& b);
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
};
std::ostream& operator<<(std::ostream& out, const Form& c);

#endif
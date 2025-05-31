/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:37:51 by asayad            #+#    #+#             */
/*   Updated: 2025/05/31 13:38:32 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <Bureaucrat.hpp>
#include <fstream>

typedef enum FORMTYPE {
    PRESIDENTIALPARDONFORM,
    ROBOTOMYREQUESTFORM,
    SHRUBBERYCREATIONFORM,
};

class Bureaucrat;
class AForm{
    private:
        const std::string name;
        bool formSigned;
        const int signature_grade;
        const int exec_grade;
    public:
        static int i;
        AForm(std::string name, int sign_grd, int exec_grd);
        AForm(const AForm& f);
        AForm& operator=(const AForm& f);
        virtual ~AForm();
        const std::string& getFormName() const;
        int getSignGrd() const;
        int getExecGrd() const;
        bool fsigned() const;
        void setFsigned(bool a);
        bool beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const& executor) const;
        virtual void executef() const = 0;
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
        class FormSignedException : public std::exception{
            public:
                const char* what() const throw();
        };
        class FileOpeningException : public std::exception{
            const char* what() const throw();
        };
        
};

#endif
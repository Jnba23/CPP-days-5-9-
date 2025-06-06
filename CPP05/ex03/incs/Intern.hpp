/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:55:54 by asayad            #+#    #+#             */
/*   Updated: 2025/06/01 12:00:39 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>

class AForm;
class Intern{
    public:
        Intern();
        Intern(const Intern& i);
        const Intern& operator=(const Intern& i);
        ~Intern();
        AForm* makeForm(const std::string& formName, const std::string& target);
        static AForm* PPform(const std::string& target);
        static AForm* RRform(const std::string& target);
        static AForm* SCform(const std::string& target);
};
class InvalidFrom : public std::exception{
    public:
        const char* what() const throw();
};

#endif
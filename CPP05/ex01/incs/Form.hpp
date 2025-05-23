/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:23:09 by asayad            #+#    #+#             */
/*   Updated: 2025/05/21 13:46:46 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <Bureaucrat.hpp>
class GradeTooHigh;
class GradeTppLow;
class Form : public GradeTooHigh, public GradeTooLow{
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
        const std::string& getFormName();
        const int getSignGrd();
        const int getExecGrd();
        bool fsigned();
        void beSigned(const Bureaucrat& b);

};

#endif
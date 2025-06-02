/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 07:40:24 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 17:08:43 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <AForm.hpp>

class ShrubberyCreationForm : public AForm {
    private:
        std::string target;
    public:
        ShrubberyCreationForm(const std::string& name);
        ShrubberyCreationForm(const ShrubberyCreationForm& s);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);
        ~ShrubberyCreationForm();
        const std::string& getTarget() const;
        void executef() const; 
};

#endif
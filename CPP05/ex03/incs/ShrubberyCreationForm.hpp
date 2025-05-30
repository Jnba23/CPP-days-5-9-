/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 07:40:24 by asayad            #+#    #+#             */
/*   Updated: 2025/05/30 13:01:16 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <iostream>
#include <AForm.hpp>

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(const std::string& name);
        ShrubberyCreationForm(const ShrubberyCreationForm& s);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& s);
        ~ShrubberyCreationForm();
        void executef() const; 
};

#endif
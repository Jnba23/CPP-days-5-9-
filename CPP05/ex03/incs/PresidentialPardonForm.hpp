/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:04:10 by asayad            #+#    #+#             */
/*   Updated: 2025/05/30 16:28:10 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include <AForm.hpp>

class PresidentialPardonForm : public AForm{
    public:
        PresidentialPardonForm(const std::string& name);
        PresidentialPardonForm(const PresidentialPardonForm& p);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& p);
        ~PresidentialPardonForm();
        void executef() const;
};

#endif
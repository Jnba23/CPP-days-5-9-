/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:04:10 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 14:36:23 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include <AForm.hpp>

class PresidentialPardonForm : public AForm{
    private:
        std::string target;
    public:
        PresidentialPardonForm(const std::string& name);
        PresidentialPardonForm(const PresidentialPardonForm& p);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& p);
        ~PresidentialPardonForm();
        const std::string& getTarget() const;
        void executef() const;
};

#endif
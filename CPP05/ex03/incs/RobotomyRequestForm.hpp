/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 08:46:27 by asayad            #+#    #+#             */
/*   Updated: 2025/05/30 16:31:52 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <AForm.hpp>

class RobotomyRequestForm : public AForm{
    public:
        RobotomyRequestForm(const std::string& name);
        RobotomyRequestForm(const RobotomyRequestForm& r);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& r);
        ~RobotomyRequestForm();
        void executef() const;
};

#endif
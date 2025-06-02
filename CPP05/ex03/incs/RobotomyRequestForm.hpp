/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 08:46:27 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 16:52:57 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <AForm.hpp>

class RobotomyRequestForm : public AForm{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& r);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& r);
        const std::string& getTarget() const;
        ~RobotomyRequestForm();
        void executef() const;
};

#endif
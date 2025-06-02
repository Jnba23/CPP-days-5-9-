/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 08:46:27 by asayad            #+#    #+#             */
/*   Updated: 2025/06/02 14:36:28 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <AForm.hpp>

class RobotomyRequestForm : public AForm{
    private:
        std::string target;
    public:
        RobotomyRequestForm(const std::string& tar);
        RobotomyRequestForm(const RobotomyRequestForm& r);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& r);
        ~RobotomyRequestForm();
        const std::string& getTarget() const;
        void executef() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:19:24 by asayad            #+#    #+#             */
/*   Updated: 2025/05/19 13:45:00 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <iostream>

class Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        std::string& getName();
        int getGrade();
        std::string operator<<(Bureaucrat& c);
}

#endif
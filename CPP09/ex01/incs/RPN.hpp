/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:15:19 by asayad            #+#    #+#             */
/*   Updated: 2025/07/13 21:56:13 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <stack>
#include <list>

class RPN{
    private:
        std::list<std::string> s;
        std::stack<double> res;
        double r;
    public:
        RPN();
        RPN(const RPN& r);
        RPN& operator=(const RPN& r);
        void fillInput(const std::string& s);
        double calculate();
        void partialRes(std::string& op);
        void checkString(const std::string& s);
        ~RPN();
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:46:57 by asayad            #+#    #+#             */
/*   Updated: 2025/07/13 21:47:57 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

RPN::RPN(){
}

RPN::RPN(const RPN& r){
    (void)r;
}

RPN& RPN::operator=(const RPN& r){
    (void)r;
    return (*this);
}

void RPN::checkString(const std::string& s){
    std::string valid = "0123456789+-*/ ";
    if (s.find_first_not_of(valid) != s.npos)
        throw(std::runtime_error("Invalid input !"));
}

void RPN::fillInput(const std::string& str){
    checkString(str);
    std::istringstream i;
    std::string ops = "+-/*";
    i.clear();
    i.str(str);
    std::string arg;
    while (i >> arg){
        if (arg.find_first_of(ops) == arg.npos){
            int n = std::strtol(arg.c_str(), NULL, 10);
            if (n < 0 || n > 9)
                throw(std::runtime_error("Big number !"));
            else
                s.push_back(arg);
        } else{
            if (arg.size() > 1)
                throw(std::runtime_error("two ops no space !"));
            s.push_back(arg);
        }
    }
}

void RPN::partialRes(std::string& op){
    double r1, r2;
    r2 = res.top();
    res.pop();
    r1 = res.top();
    if (op == "+")
        r = r1 + r2;
    else if (op == "-")
        r = r1 - r2;
    else if (op == "*")
        r = r1 * r2;
    else if (op == "/"){
        if (r2 == 0)
            throw(std::runtime_error("Division by 0 !"));
        r = r1 / r2;
    }
    res.pop();
    res.push(r);
    return ;
}

double RPN::calculate(){
    std::string ops = "+-*/";
    for (std::list<std::string>::iterator it = s.begin(); it != s.end(); it++){
        if (it->find_first_of(ops) == it->npos){
            res.push(std::strtod(it->c_str(), NULL));
        } else if (it->find_first_of(ops) != it->npos){
            if (res.size() < 2)
                throw(std::runtime_error("Not enough operands !"));
            partialRes(*it);
        }
    }
    return(res.top());
}

RPN::~RPN(){
}
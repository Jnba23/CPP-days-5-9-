/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:18:45 by asayad            #+#    #+#             */
/*   Updated: 2025/06/17 17:25:17 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>

ScalarConverter::ScalarConverter(){
    std::cout << "Scalar converter constructor called !" << '\n';
}

ScalarConverter::ScalarConverter(const ScalarConverter& s){
    (void)s;
    std::cout << "ScalarConverter copy constructor called !" << '\n';
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& s){
    std::cout << "ScalarConverter assignment opertor called !" << '\n';
    (void)s;
    return (*this);
}

ScalarConverter::~ScalarConverter(){
    std::cout << "ScalarConverter destructor called !" << '\n';
}

void ScalarConverter::convert(const std::string &s){
    //pseudo-literals
    if (pseudoLiteral(s))
        return ;
    //char, int, flaot, double
    if (std::isalpha(s[0]) && s.size() == 1){
        isChar(s[0]);
    }
    if (std::isdigit(s[0]))
}

void isChar(char c){
    std::cout << "char : " << c << '\n';
    std::cout << "int : " << static_cast<int>(c) << '\n';
    std::cout << "float : " << static_cast<float>(c) << '\n';
    std::cout << "double : " << static_cast<double>(c) << '\n'; 
}
// std::cout << "int : " << static_cast<int>(s[0]) << '\n';
// std::cout << "float : " << static_cast<float>(s[0]) << '\n';
// std::cout << "double : " << static_cast<double>(s[0]) << '\n';

int pseudoLiteral(const std::string& s){
    static std::string p[6] = {"+inf", "-inf", "nan", "+inff", "-inff", "nanf"};
    for (int i = 0; i < 6; i++){
        if (s == p[i]){
            std::cout << "char : impossible" << '\n';
            std::cout << "int : impossible" << '\n';
            if (s.compare("+inf")){
                std::cout << "float: inff" << '\n';
                std::cout << "double: inf" << '\n';
            }
            if (s.compare("-inf")){
                std::cout << "float: -inff" << '\n';
                std::cout << "double: -inf" << '\n';
            }
            if (s.compare("-inff")){
                std::cout << "float: -inff" << '\n';
                std::cout << "double: -inf" << '\n';
            }
            if (s.compare("+inff")){
                std::cout << "float: +inff" << '\n';
                std::cout << "double: +inf" << '\n';
            }
            if (s.compare("nan")){
                std::cout << "float: nanf" << '\n';
                std::cout << "double: nan" << '\n';
            }
            if (s.compare("nanf")){
                std::cout << "float: nanf" << '\n';
                std::cout << "double: nan" << '\n';
            }
            return (1);
        }
    }
    return (0);
}
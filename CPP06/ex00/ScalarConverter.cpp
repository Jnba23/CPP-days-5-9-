/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:18:45 by asayad            #+#    #+#             */
/*   Updated: 2025/06/20 18:14:33 by asayad           ###   ########.fr       */
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
    if (std::isprint(s[0]) && s.size() == 1){
        isChar(s[0]);
    }
    else if (std::isdigit(s[0]) || s[0] == '+' || s[0] == '-' || s[0] == '.'){
        isNum(s);
    }
}

void isChar(char c){
    std::cout << "char : '" << c << "'" << '\n';
    int i = c;
    float f = c;
    double d = c;
    std::cout << "int : " << i << '\n';
    std::cout << "float : " << f << ".0f" << '\n';
    std::cout << "double : " << d << ".0" << '\n'; 
}

void isNum(const std::string& s){
    char* end;
    strtod(s.c_str(), &end);
    if (*end != '\0' && (*end != 'f' || *(end + 1) != '\0')){
        std::cout << "char: impossible" << '\n';
        std::cout << "int: impossible" << '\n';
        std::cout << "float: impossible" << '\n';
        std::cout << "double: impossible" << '\n';
        return;
    }
    if (s.find('.') == s.npos && s.find('f') == s.npos)
        isInt(s);
    if (s.find('.') != s.npos && s.find('f') != s.npos)
        isFloat(s);
    if (s.find('.') != s.npos && s.find('f') == s.npos)
        isDouble(s);
}

void isInt(const std::string& v){
    long long i = strtoll(v.c_str(), NULL, 10);
    if (i > INT_MAX || i < INT_MIN){
            std::cout << "char: impossible" << '\n';
            std::cout << "int: impossible" << '\n';
        if (errno == ERANGE){
            std::cout << "float : impossible" << '\n';
            std::cout << "double : impossible" << '\n';
        }
        else{
            std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
            std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(i) << '\n';
        }
        return;
    }
    if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
        std::cout << "char : impossible" << '\n';
    else if (i >= 32 && i <= 126)
        std::cout << "char : '" << static_cast<char>(i) << "'" << '\n';
    else
        std::cout << "char : non printable" << '\n';
    std::cout << "int : " << i << '\n';
    std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f\n";
    std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(i) << "\n";
}

void isFloat(const std::string& v){
    float f = strtof(v.c_str(), NULL);
    if (errno == ERANGE){
        std::cout << "char: impossible" << '\n';
        std::cout << "int: impossible" << '\n';
        std::cout << "float: impossible" << '\n';
        std::cout << "double : impossible" << '\n';
        return ;
    }
    if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min()){
        std::cout << "char : impossible" << '\n';
    } else if (f >= 32 && f <= 126)
        std::cout << "char : '" << static_cast<char>(f) << "'" << '\n';
    else
        std::cout << "char : non printable" << '\n';
    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
        std::cout << "int : impossible" << '\n';
    else
        std::cout << "int : " << static_cast<int>(f) << "\n";
    std::cout << "float : " << std::fixed << std::setprecision(1) << f << "f\n";
    std::cout << "double : " << std::fixed << std::setprecision(1) << static_cast<double>(f) << '\n';
}

void isDouble(const std::string& s){
    double d = strtod(s.c_str(), NULL);
    if (errno == ERANGE){
        std::cout << "char: impossible" << '\n';
        std::cout << "int: impossible" << '\n';
        std::cout << "float: impossible" << '\n';
        std::cout << "double: impossible" << '\n';
        return ;
    }
    if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min()){
        std::cout << "char : impossible" << '\n';
    } else if (d >= 32 && d <= 126)
        std::cout << "char : '" << static_cast<char>(d) << "'" << '\n';
    else
        std::cout << "char : non printable" << '\n';
    if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "int : impossible" << '\n';
    else
        std::cout << "int : " << static_cast<int>(d) << "\n";
    if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
        std::cout << "float : impossible" << '\n';
    else
        std::cout << "float : " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
    std::cout << "double : " << std::fixed << std::setprecision(1) << d << '\n';
}

int pseudoLiteral(const std::string& s){
    static std::string p[6] = {"+inf", "-inf", "nan", "+inff", "-inff", "nanf"};
    for (int i = 0; i < 6; i++){
        if (s == p[i]){
            std::cout << "char : impossible" << '\n';
            std::cout << "int : impossible" << '\n';
            if (!s.compare("+inf")){
                std::cout << "float: inff" << '\n';
                std::cout << "double: inf" << '\n';
            }
            if (!s.compare("-inf")){
                std::cout << "float: -inff" << '\n';
                std::cout << "double: -inf" << '\n';
            }
            if (!s.compare("-inff")){
                std::cout << "float: -inff" << '\n';
                std::cout << "double: -inf" << '\n';
            }
            if (!s.compare("+inff")){
                std::cout << "float: +inff" << '\n';
                std::cout << "double: +inf" << '\n';
            }
            if (!s.compare("nan")){
                std::cout << "float: nanf" << '\n';
                std::cout << "double: nan" << '\n';
            }
            if (!s.compare("nanf")){
                std::cout << "float: nanf" << '\n';
                std::cout << "double: nan" << '\n';
            }
            return (1);
        }
    }
    return (0);
}
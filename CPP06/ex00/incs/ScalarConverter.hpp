/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:04:01 by asayad            #+#    #+#             */
/*   Updated: 2025/06/17 17:20:00 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <sstream>
#include <cctype>
#include <iomanip>

class ScalarConverter {
    private:
        ScalarConverter();
    public:
        ScalarConverter(const ScalarConverter& s);
        ScalarConverter& operator=(const ScalarConverter& s);
        static void convert(const std::string& s);
        ~ScalarConverter();
    };
    int pseudoLiteral(const std::string& s);
    void isChar(char c);
    void sToint(const std::string& s);
    void sTofloat(const std::string& s);
    void sTodouble(const std::string& s);

#endif
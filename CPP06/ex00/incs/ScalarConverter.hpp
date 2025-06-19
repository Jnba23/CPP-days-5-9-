/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:04:01 by asayad            #+#    #+#             */
/*   Updated: 2025/06/18 19:34:23 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <climits>
#include <limits>
#include <errno.h>

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
    void isNum(const std::string& s);
    void isInt(const std::string& s);
    void isFloat(const std::string& s);
    void isDouble(const std::string& s);

#endif
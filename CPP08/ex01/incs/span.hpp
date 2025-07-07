/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:33:12 by asayad            #+#    #+#             */
/*   Updated: 2025/07/07 12:11:57 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <climits>

class Span {
    private:
        unsigned int capacity;
    public:
        std::vector<int> v;
        Span();
        Span(unsigned int N);
        Span(const Span& sc);
        Span& operator=(const Span& s);
        unsigned int getCapacity() const;
        void addNumber(int n);
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void expandVec(const std::vector<int>& v);
        ~Span();
        
};

class OutOfRange : public std::exception{
    public:
        const char* what() const throw();
};

class ExceedRange : public std::exception{
    public:
        const char* what() const throw();
};

class OneElemContainer : public std::exception{
    public:
        const char* what() const throw();
};

#endif
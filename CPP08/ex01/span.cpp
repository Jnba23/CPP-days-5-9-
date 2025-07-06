/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:39:15 by asayad            #+#    #+#             */
/*   Updated: 2025/07/03 13:09:01 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <span.hpp>

Span::Span(): capacity(10){
}

Span::Span(unsigned int N): capacity(N){
}

Span::Span(const Span& sc): capacity(sc.getCapacity()), v(sc.v){
}

void Span::addNumber(int n){
    if (v.size() >= capacity)
        throw(OutOfRange());
    v.push_back(n);
}

Span& Span::operator=(const Span& sc){
    if (this != &sc){
        capacity = sc.getCapacity();
        v = sc.v;
    }
    return (*this);
}

unsigned int Span::getCapacity() const{
    return (capacity);
}

const char* OutOfRange::what() const throw(){
    return ("Container full !");
}

const char* OneElemContainer::what() const throw(){
    return ("Empty or Container have one element !");
}

unsigned int Span::shortestSpan(){
    unsigned int s = UINT_MAX;
    if (v.size() <= 1)
        throw(OneElemContainer());
    std::sort(v.begin(), v.end());
    for (std::vector<int>::const_iterator i = v.begin() + 1; i != v.end(); i++){
        if (s >= static_cast<unsigned int>(((*i - *(i - 1)))))
            s = static_cast<unsigned int>(((*i - *(i - 1))));
    }
    return (s);
}

unsigned int Span::longestSpan(){
    if (v.size() <= 1)
    throw(OneElemContainer());
    std::vector<int>::iterator b = v.begin();
    std::vector<int>::iterator e = v.end();
    unsigned int s = *(std::max_element(b, e)) - *(std::min_element(b, e));
    return (s);
}

Span::~Span(){};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:39:15 by asayad            #+#    #+#             */
/*   Updated: 2025/07/07 20:09:24 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <span.hpp>

Span::Span(): capacity(10){
}

Span::Span(unsigned int n): capacity(n){
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

const char* ExceedRange::what() const throw(){
    return ("Max capacity will be exceeded !");
}

const char* OneElemContainer::what() const throw(){
    return ("Empty or Container have one element !");
}

unsigned int Span::shortestSpan(){
    unsigned int s = UINT_MAX;
    std::vector<unsigned int> tmp;
    if (v.size() == 1 || v.empty())
        throw(OneElemContainer());
    std::vector<int> sorted = v;
    std::sort(sorted.begin(), sorted.end());
    for (std::vector<int>::const_iterator i = sorted.begin(); i != sorted.end() - 1; i++){
        unsigned int diff = static_cast<unsigned int> (*(i + 1) - *i);
        if (s > diff)
            s = diff;
    }
    return (s);
}

unsigned int Span::longestSpan(){
    if (v.size() == 1 || v.empty())
        throw(OneElemContainer());
    std::vector<int>::iterator b = v.begin();
    std::vector<int>::iterator e = v.end();
    unsigned int s = *(std::max_element(b, e)) - *(std::min_element(b, e));
    return (s);
}

void Span::expandVec(const std::vector<int>& e){
    unsigned int i = std::distance(e.begin(), e.end());
    if (v.size() + i > capacity)
        throw (ExceedRange());
    v.insert(v.end(), e.begin(), e.end());
}

Span::~Span(){};
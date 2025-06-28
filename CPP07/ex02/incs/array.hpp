/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 11:26:52 by asayad            #+#    #+#             */
/*   Updated: 2025/06/28 17:30:08 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <new>

template <typename T>
class Array{
    private:
        T* a;
        unsigned int  s;
    public:
        Array(){
            s = 0;
            a = new T[0];
        }
        Array(unsigned int n){
            s = n;
            a = new T[n];
            for (unsigned int i = 0; i < n; i++){
                a[i] = T();
            }
        }
        Array(const Array& p): s(p.size()){
            a = new T[s];
            for (unsigned int i = 0; i < s; i++)
                a[i] = p.a[i];
        }
        Array& operator=(const Array& p){
            if (this != &p){
                delete[] a;
                s = p.size();
                a = new T[s];
                for (unsigned int j = 0; j < s; j++){
                    a[j] = p.a[j];
                }
            }
            return (*this);
        }
        class OutofBound: public std::exception{
            public:
                const char* what()const throw(){
                    return ("Index out of bound !");
                }
        };
        unsigned int size()const{return (s);}
        T& operator[](int index){
            if (index >= static_cast<int>(s))
                throw(OutofBound());
            return (a[index]);
        };
        const T& operator[](unsigned int index) const{
            if (index >= static_cast<int>(s))
                throw(OutofBound());
            return (a[index]);
        };
        ~Array(){
            delete[] a;
        }
};



#endif
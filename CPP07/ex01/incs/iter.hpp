/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:45:04 by asayad            #+#    #+#             */
/*   Updated: 2025/06/25 22:00:44 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T, typename Func>
void iter(T* a, size_t b, Func f){
    for (size_t i = 0; i < b; i++){
        f(a[i]);
    }
}
template <typename T>
void f(T& a){
    std::cout << a << '\n';
}

#endif
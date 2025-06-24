/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:54:41 by asayad            #+#    #+#             */
/*   Updated: 2025/06/24 12:30:03 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
#define HEADER_HPP
#include <iostream>

template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b){
    if (a > b)
        return (b);
    else if (a < b)
        return (a);
    return (b);
}

template <typename T>
T max(T a, T b){
    if (a > b)
      return (a);
    else if (a < b)
        return (b);
    return (b);
}

#endif
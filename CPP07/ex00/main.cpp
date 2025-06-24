/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:25:23 by asayad            #+#    #+#             */
/*   Updated: 2025/06/24 12:34:37 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<header.hpp>

int main(){
    int a = 6;
    int b = 9;
    double c = 2.56;
    double d = 3.5;
    std::cout << "min a & b : " << min(a, b) << '\n';
    std::cout << "max a & b : " << max(a, b) << '\n';
    swap(a, b);
    std::cout << "a : " << a << " b : " << b << '\n';
    std::cout << "min c & d : " << min(c, d) << '\n';
    std::cout << "max c & d : " << max(c, d) << '\n';
    swap(c, d);
    std::cout << "a : " << c << " b : " << d << '\n';
}
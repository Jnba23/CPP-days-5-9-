/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:09:43 by asayad            #+#    #+#             */
/*   Updated: 2025/06/28 17:29:11 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array.hpp>

int main(){
    try {
        Array<int> dd(1);
        dd[0] = 1;
        std::cout << dd[0] << '\n';
        Array<int> a(5);
        a[3] = 4;
        std::cout << a[3] << '\n' << a[4] << '\n';
        Array<int> b(a);
        std::cout << a[4] << '\n';
    } catch (const std::exception& e){
        std::cout << e.what() << '\n';
    }
}
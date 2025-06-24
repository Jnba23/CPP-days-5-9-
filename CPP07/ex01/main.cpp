/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:44:59 by asayad            #+#    #+#             */
/*   Updated: 2025/06/24 17:00:01 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>

int main(){
    int arr[5] = {5, 6, 8, -9, 7};
    iter(arr, 5, static_cast<void (*)(const int&)>(f));
    int *a = new int[4];
    a[0] = -6;
    a[1] = 10;
    a[2] = 27;
    a[3] = -2;
    std::cout << "before iter : " << '\n';
    for (int i = 0; i < 4; i++){
        std::cout << a[i] << " ";
    }
    std::cout << '\n';
    iter(a, 4, static_cast<void(*)(int&)>(f));
    std::cout << "After iter : " << '\n';
    for (int i = 0; i < 4; i++){
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}
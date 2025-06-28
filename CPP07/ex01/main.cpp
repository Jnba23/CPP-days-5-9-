/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:44:59 by asayad            #+#    #+#             */
/*   Updated: 2025/06/28 11:23:46 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iter.hpp>

int main(){
    const int arr[5] = {5, 6, 8, -9, 7};
    iter(arr, 5, f<const int>);
    int *a = new int[4];
    a[0] = -6;
    a[1] = 10;
    a[2] = 27;
    a[3] = -2;
    for (int i = 0; i < 4; i++){
        std::cout << a[i] << " ";
    }
    iter(a, 4, f<int>);
    for (int i = 0; i < 4; i++){
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
    char c[6] = "Hello";
    iter(c, 5, f<char>);
}
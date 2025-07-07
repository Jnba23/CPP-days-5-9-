/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:23:37 by asayad            #+#    #+#             */
/*   Updated: 2025/07/07 18:31:03 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <easyfind.hpp>

int main(){
    std::vector<int> v;
    v.push_back(5);
    v.push_back(8);
    v.push_back(11);
    try{
        easyfind(v, 8);
    } catch (const std::exception& c){
        std::cout << c.what() << '\n';
    }
    std::list<int> l;
    l.push_back(2);
    l.push_back(52);
    l.push_back(-33);
    try{
        easyfind(l, 5);
    } catch (const std::exception& c){
        std::cout << c.what() << '\n';
    }
    std::deque<int> d;
    d.push_back(100);
    d.push_front(-98);
    d.push_back(25);
    try{
        easyfind(d, 100);
    } catch (const std::exception& c){
        std::cout << c.what() << '\n';
    }
}
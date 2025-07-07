/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:26:30 by asayad            #+#    #+#             */
/*   Updated: 2025/07/07 18:30:39 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <exception>

class NotFound : public std::exception{
    public:
        const char* what() const throw();
};

template <typename T>
void easyfind(const T& c, int s){
    if (std::find(c.begin(), c.end(), s) != c.end()){
        std::cout << "Element " << s << " found in the container !" << '\n';
        return ;
    }
    throw(NotFound());
}

#endif
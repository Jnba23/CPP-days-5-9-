/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:26:30 by asayad            #+#    #+#             */
/*   Updated: 2025/07/02 11:54:46 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>

class NotFound : public std::exception{
    public:
        const char* what() const throw();
};

template <typename T>
void easyfind(const T& c, int s){
    for (typename T::const_iterator a = c.begin(); a != c.end(); a++){
        if (*a == s){
            std::cout << "Element " << s << " found in the container !" << '\n';
            return ;
        }
    }
    throw(NotFound());
}

#endif
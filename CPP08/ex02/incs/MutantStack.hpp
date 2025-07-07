/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:18:44 by asayad            #+#    #+#             */
/*   Updated: 2025/07/07 20:52:13 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >{
    public:
    MutantStack();
    MutantStack(const MutantStack& ms);
    MutantStack& operator=(const MutantStack& cMs);
    typedef typename std::deque<T>::iterator iterator; 
    typedef typename std::deque<T>::const_iterator const_iterator; 
    iterator begin(){
        return (this->c.begin());
    };
    iterator end(){
        return (this->c.end());
    }
    const_iterator begin() const{
        return (this->c.begin());
    };
    const_iterator end() const{
        return (this->c.end());
    }
    ~MutantStack();
};
#include <MutantStack.tpp>

#endif
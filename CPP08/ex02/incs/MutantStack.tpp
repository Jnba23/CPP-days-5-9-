/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:30:21 by asayad            #+#    #+#             */
/*   Updated: 2025/07/07 20:51:05 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

#include <MutantStack.hpp>

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T, std::deque<T> >(){
};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& ms): std::stack<T, std::deque<T> >(ms){
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& ms){
    if (this != &ms){
        std::stack<T, std::deque<T> >::operator=(ms);
    }
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(){};

#endif
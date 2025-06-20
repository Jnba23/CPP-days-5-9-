/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpFuncs.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 11:29:23 by asayad            #+#    #+#             */
/*   Updated: 2025/06/20 11:31:01 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <classA.hpp>
#include <classB.hpp>
#include <classC.hpp>

void identify(Base* x){
    A* a = dynamic_cast<A*>(x);
    B* b = dynamic_cast<B*>(x);
    C* c = dynamic_cast<C*>(x);
    if (a != NULL)
        std::cout << a->getType() << '\n';
    if (b != NULL)
        std::cout << b->getType() << '\n';
    if (c != NULL)
        std::cout << c->getType() << '\n';
    return;
}

void identify(Base& x){
    try{
        A a = dynamic_cast<A&>(x);
        std::cout << a.getType() << '\n';
        return ;
    } catch (const std::exception& e){
        std::cout << e.what() << " A failed :" << '\n';
    }
    try {
        B b = dynamic_cast<B&>(x);
        std::cout << b.getType() << '\n';
        return ;
    } catch (const std::exception& e){
        std::cout << e.what() << " B failed :" << '\n';
    }
    try {
        C c = dynamic_cast<C&>(x);
        std::cout << c.getType() << '\n';
        return ;
    } catch (const std::exception& e){
        std::cout << e.what() << " C failed :" << '\n';
    }
}
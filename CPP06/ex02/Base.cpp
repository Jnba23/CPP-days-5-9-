/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:54:38 by asayad            #+#    #+#             */
/*   Updated: 2025/06/20 11:29:16 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <classA.hpp>
#include <classB.hpp>
#include <classC.hpp>

Base::~Base(){
    std::cout << "Base destructor called !" << '\n';
}

Base* generate(void){
    int i = rand() % 3;
    switch (i) {
        case 0 :
            return new A;
        case 1 :
            return new B;
        case 2 :
            return new C;
    }
    std::cout << "generate failed !" << '\n';
    return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:30:12 by asayad            #+#    #+#             */
/*   Updated: 2025/06/20 11:31:44 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Base.hpp>
#include <classA.hpp>
#include <classB.hpp>
#include <classC.hpp>

int main(){
    srand(time(NULL));
    Base* a = generate();
    Base* x = generate();
    Base& b = *x;
    identify(a);
    identify(b);
}
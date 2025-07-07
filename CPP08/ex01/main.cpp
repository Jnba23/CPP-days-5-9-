/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:24:54 by asayad            #+#    #+#             */
/*   Updated: 2025/07/07 20:10:43 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <span.hpp>
#include <limits.h>
int main(){
    try{
        Span sp = Span(500);
        
        sp.addNumber(INT_MIN);
        sp.addNumber(52);
        sp.addNumber(599);
        sp.addNumber(-1);
        sp.addNumber(INT_MAX);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        Span a(1);
        a.expandVec(sp.v);
        std::cout << "a shortest span : " << a.shortestSpan() << std::endl;
        std::cout << "a longest span : " << a.longestSpan() << std::endl;
        
    } catch (const std::exception& e){
        std::cout << e.what() << '\n';
    }
    return 0;
}
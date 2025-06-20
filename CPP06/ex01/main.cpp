/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 23:12:01 by asayad            #+#    #+#             */
/*   Updated: 2025/06/19 23:17:06 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serializer.hpp>

int main(){
    struct Data a;
    a.i = 5;
    uintptr_t b = Serializer::serialize(&a);
    Data* c = Serializer::deserialize(b);
    std::cout << "a = " << a.i << " b = " << b << " c = " << c->i; 
}
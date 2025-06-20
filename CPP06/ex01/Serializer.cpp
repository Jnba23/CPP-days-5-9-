/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:27:24 by asayad            #+#    #+#             */
/*   Updated: 2025/06/19 23:18:51 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Serializer.hpp>

Serializer::Serializer(){};

Serializer::Serializer(const Serializer& s){(void)s;};

Serializer& Serializer::operator=(const Serializer& s){(void)s; return(*this);};

Serializer::~Serializer(){};

uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t v = reinterpret_cast<uintptr_t>(ptr);
    return (v);
}

Data* Serializer::deserialize(uintptr_t raw){
    Data* p = reinterpret_cast<Data*>(raw);
    return (p);
}
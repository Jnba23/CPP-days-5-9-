/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:05:29 by asayad            #+#    #+#             */
/*   Updated: 2025/06/19 23:15:07 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER
#define SERIALIZER
#include <iostream>
#include <stdint.h>
#include <Data.hpp>

class Serializer{
    private:
        Serializer();
        Serializer(const Serializer& s);
        Serializer& operator=(const Serializer& s);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
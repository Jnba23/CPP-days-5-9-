/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:33:33 by asayad            #+#    #+#             */
/*   Updated: 2025/06/20 11:24:13 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

class Base{
    public :
        virtual ~Base();
    };
    
void identify(Base* p);
void identify(Base& r);
Base* generate(void);
#endif
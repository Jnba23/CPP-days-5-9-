/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:38:56 by asayad            #+#    #+#             */
/*   Updated: 2025/06/20 10:51:11 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSB_HPP
#define CLASSB_HPP

#include<Base.hpp>

class B : public Base{
    private:
        std::string type;
    public:
        B();
        const std::string& getType() const;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:35:14 by asayad            #+#    #+#             */
/*   Updated: 2025/06/20 11:22:25 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSA_HPP
#define CLASSA_HPP

#include<Base.hpp>

class A : public Base{
    private:
        std::string type;
    public:
        A();
        const std::string& getType() const;
};

#endif
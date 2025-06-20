/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classC.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 09:39:38 by asayad            #+#    #+#             */
/*   Updated: 2025/06/20 10:51:18 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSC_HPP
#define CLASSC_HPP

#include<Base.hpp>

class C : public Base{
    private:
        std::string type;
    public:
        C();
        const std::string& getType() const;
};

#endif
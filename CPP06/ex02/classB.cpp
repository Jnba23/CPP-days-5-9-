/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:51:32 by asayad            #+#    #+#             */
/*   Updated: 2025/06/20 11:25:49 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <classB.hpp>

B::B(){
    type = "B";    
}

const std::string& B::getType() const{
    return (type);
}
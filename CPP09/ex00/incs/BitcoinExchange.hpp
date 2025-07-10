/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:32:01 by asayad            #+#    #+#             */
/*   Updated: 2025/07/09 22:21:59 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

class BitcoinEx {
    private:
        std::map<int, float> data;
    public:
        BitcoinEx();
        BitcoinEx(const BitcoinEx& b);
        BitcoinEx& operator=(const BitcoinEx& b);
        void fillData();
        std::pair<int, float> fetchData();
        ~BitcoinEx();
};

#endif
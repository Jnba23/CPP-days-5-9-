/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:32:01 by asayad            #+#    #+#             */
/*   Updated: 2025/07/10 19:34:31 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <fstream>
#include <sstream>

class BitcoinEx {
    private:
        std::map<int, float> data;
    public:
        BitcoinEx();
        BitcoinEx(const BitcoinEx& b);
        BitcoinEx& operator=(const BitcoinEx& b);
        void fillData();
        std::pair<int, float> fetchData() const;
        ~BitcoinEx();
};

void search(const BitcoinEx& db, std::fstream& in);
void checkErrors(const std::string& date, const std::string& value);

class InputError : public std::exception{
};

#endif
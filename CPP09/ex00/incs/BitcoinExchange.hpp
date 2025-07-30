/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:32:01 by asayad            #+#    #+#             */
/*   Updated: 2025/07/30 12:16:22 by asayad           ###   ########.fr       */
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
#include <climits>

class BitcoinEx {
    private:
        std::map<int, float> data;
    public:
        BitcoinEx();
        BitcoinEx(const BitcoinEx& b);
        BitcoinEx& operator=(const BitcoinEx& b);
        void fillData();
        float fetchData(const int d) const;
        ~BitcoinEx();
};

struct DateCmpnt{
    std::string Date;
    std::string year;
    std::string month;
    std::string day;
};

void search(const BitcoinEx& db, std::fstream& in);
void searchDb(const BitcoinEx& db, std::string date, std::string value);
void checkErrors(const std::string& date, const std::string& value);

#endif
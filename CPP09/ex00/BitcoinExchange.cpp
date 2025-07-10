/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:36:15 by asayad            #+#    #+#             */
/*   Updated: 2025/07/10 20:07:11 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinEx::BitcoinEx(){
};

BitcoinEx::BitcoinEx(const BitcoinEx& c){
    *this = c;
}

BitcoinEx& BitcoinEx::operator=(const BitcoinEx& b){
    if (this != &b){
        data = b.data;
    }
    return (*this);
}

void BitcoinEx::fillData(){
    std::ifstream in("data.csv");
    if (!in){
        std::cout << "Failed !" << '\n';
    }
    std::string input;
    while (std::getline(in, input)){
        std::string date = input.substr(0, 10);
        for (size_t i = 0; i < date.size(); i++){
            if (date[i] == '-')
                date.erase(i, 1);
        }
        std::string value = input.substr(12, input.size());
        std::pair<int, float> pair = std::make_pair(std::strtol(date.c_str(), NULL, 10), std::strtof(value.c_str(), NULL));
        data.insert(pair);
    }
}

BitcoinEx::~BitcoinEx(){
    std::cout << "Destructor called" << std::endl;
}

void checkErrors(const std::string& date, const std::string& value){
    std::istringstream i(date);
    std::string cpnt;
    int counter;
    while (std::getline(i, cpnt, '-')){
        counter++;
        if (counter > 2)
            throw (std::runtime_error("Error Date ==> " + date));
        
    }
}

void search(const BitcoinEx& db, std::fstream& in){
    (void)db;
    std::string input;
    std::istringstream i;
    std::string date;
    std::string value;
    
    std::getline(in, input);
    while (std::getline(in, input)){
        i.clear();
        i.str(input);
        std::getline(i, date, '|');
        std::getline(i, value, '|');
        try {
            checkErrors(date, value);
        } catch (const std::exception& e){
            std::cout << e.what() << '\n';
            continue ;
        }
    }
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:36:15 by asayad            #+#    #+#             */
/*   Updated: 2025/07/30 14:07:26 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>
#include <iomanip>

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

void BitcoinEx::fillData(){ //give wrong value when filling data
    std::ifstream in("data.csv");
    if (!in){
        throw(std::runtime_error("Failed opening the database file !"));
    }
    std::string input;
    std::getline(in, input);
    if (input != "date,exchange_rate")
        throw(std::runtime_error("Invalid DataBase !"));
    while (std::getline(in, input)){
        std::string date = input.substr(0, 10);
        for (size_t i = 0; i < date.size(); i++){
            if (date[i] == '-')
                date.erase(i, 1);
        }
        std::string value = input.substr(11, input.size());
        std::pair<int, float> pair = std::make_pair(std::strtol(date.c_str(), NULL, 10), std::strtof(value.c_str(), NULL));
        data.insert(pair);
    }
    if (data.empty()){
        throw (std::runtime_error("Empty DataBase !"));
    }
}

BitcoinEx::~BitcoinEx(){
}

void checkErrors(const std::string& date, const std::string& value){
    std::istringstream i;
    i.clear();
    i.str(date);
    DateCmpnt cpnts;
    int counter = 0;
    while (std::getline(i, cpnts.Date, '-')){
        if (counter > 2)
            throw (std::runtime_error("Date => " + date));
        if (counter == 0){
            cpnts.year = cpnts.Date;
            int year;
            std::istringstream y;
            y.clear();
            y.str(cpnts.year);
            y >> year;
            if (!y || !y.eof() || year > 9999 || year <= 0)
                throw(std::runtime_error("Year => " + date));
        }
        if (counter == 1){
            cpnts.month = cpnts.Date;
            if (cpnts.month.size() != 2)
                throw(std::runtime_error("Month => " + date));
            int month;
            std::istringstream m;
            m.clear();
            m.str(cpnts.month);
            m >> month;
            if (!m || !m.eof() || month > 12 || month < 1)
                throw(std::runtime_error("Month => " + date));
        }
        if (counter == 2){
            cpnts.day = cpnts.Date;
            if (cpnts.day.size() != 3)
                throw(std::runtime_error("day => " + date));
            int day;
            std::istringstream d;
            d.clear();
            d.str(cpnts.day);
            d >> day;
            if (!d)
                throw(std::runtime_error("Day => " + date));
            if (d.get() != ' ')
            {
                std::cout << day << '\n';
                throw(std::runtime_error("Day => " + date));
            }
            if (cpnts.month == "02"){
                if (day > 29 || day < 1)
                    throw(std::runtime_error("February days : 1 - 29 => " + date));
                int i = std::strtol(cpnts.year.c_str(), NULL, 10);
                if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)){
                    if (day > 28 || day < 1)
                        throw(std::runtime_error("Non-Leap year February days : 1 - 28 => " + date));
                } 
            } else {
                if (day > 31 || day < 1){
                    throw(std::runtime_error("Day : 1 - 31 => " + date));
                }
            }
        }
        counter++;
    }
    std::istringstream v;
    v.clear();
    v.str(value);
    float  val;
    v >> val;
    if (!v)
        throw(std::runtime_error("Invalid input !"));
    if (!v.eof())
        throw(std::runtime_error("non-number or trailing whitespace !"));
    if (val < 0)
        throw(std::runtime_error("not a positive value !"));
    if (val > 1000)
        throw(std::runtime_error("too large a value !"));
}

float BitcoinEx::fetchData(const int d) const{
    std::map<int, float>::const_iterator it = data.find(d);
    if (it != data.end())
        return (it->second);
    it = data.lower_bound(d);
    if (it == data.begin())
        return (it->second);
    else{
        --it;
        return (it->second);
    }
    return (0.0);
}

void searchDb(const BitcoinEx& db, std::string date, std::string value){
    std::string od = date;
    for (size_t i = 0; i < od.size(); i++){
        if (od[i] == '-')
            od.erase(i, 1);
    }
    int d = std::strtol(od.c_str(), NULL, 10);
    float v =  std::strtof(value.c_str(), NULL);
    float r = db.fetchData(d);
    std::cout << date << "=>" << value << " = " << r * v << '\n';
}

void search(const BitcoinEx& db, std::fstream& in){
    std::string input;
    std::istringstream i;
    std::string date;
    std::string value;
    std::getline(in, input);
    if (input != "date | value")
        throw (std::runtime_error("Invalid input file !"));
    while (std::getline(in, input)){
        if (input.empty())
            break ;
        i.clear();
        i.str(input);
        try{
            std::getline(i, date, '|');
            if (i.eof())
                throw(std::runtime_error("Invalid input !"));
        }catch(const std::exception& e){
            std::cout << "Error : " << e.what() << '\n';
            continue;
        } 
        std::getline(i, value, '|');
        try {
            checkErrors(date, value);
            searchDb(db, date, value);
        } catch (const std::exception& e){
            std::cout << "Error : " << e.what() << '\n';
            continue ;
        }
    }
}
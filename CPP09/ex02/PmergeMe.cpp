/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:02:46 by asayad            #+#    #+#             */
/*   Updated: 2025/07/16 12:05:03 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe& p){
    (void)p;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& p){
    (void)p;
    return (*this);
}

PmergeMe::~PmergeMe(){
}

void PmergeMe::parseInput(int ac, char** av){
    std::istringstream in;
    int tmp;
    std::set<int>tmps;
    for (int i = 1; i < ac; i++){
        in.clear();
        in.str(av[i]);
        in >> tmp;
        if (!in || !in.eof() || tmp < 0)
            throw (std::runtime_error("Invalid input !"));
        if (tmps.find(tmp) != tmps.end())
            throw (std::runtime_error("Duplicate numbers !"));
        tmps.insert(tmp);
    }
}

void PmergeMe::FillVecs(int ac, char** av){
    std::istringstream in;
    int tmp;
    std::cout << "Before : ";
    for (int i = 1; i < ac; i++){
        in.clear();
        in.str(av[i]);
        in >> tmp;
        std::cout << tmp << ' ';
        mainInit.push_back(tmp);
    }
    std::cout << '\n';
}

void PmergeMe::Insert(std::vector<int>& m, std::vector<int>& p){
    std::vector<int> j;
    j.push_back(0);
    j.push_back(1);
    for (size_t i = 2; i < 50; i++){
        j.push_back(j[i - 1] + 2 * j[i - 2]);
    }
    for(std::vector<int>::iterator it = j.begin(); it != j.end(); it++){
        std::cout << "Jacobsthale idx : " << *it << '\n';
    }
    (void)p;
    (void)m;
}

std::vector<int> PmergeMe::sort(std::vector<int>& v){
    std::vector<int> main;
    std::vector<int> pending;
    for (size_t i = 1; i <= v.size(); i++){
        if (i != 0 && i % 2 == 0){
            std::pair<int, int> p = std::make_pair<int, int>(v[i - 1], v[i - 2]);
            main.push_back(std::max(p.first, p.second));
            pending.push_back(std::min(p.first, p.second));
        }
    }
    if (!v.empty() && v.size() % 2 != 0)
        pending.push_back(v[v.size() - 1]);
    while (main.size() > 1)
        main = sort(main);
    Insert(main, pending);
    std::cout << "Main :" << '\n';
    for (std::vector<int>::iterator i = main.begin(); i != main.end(); i++){
        std::cout << *i << '\n';
    }
    std::cout << "Pending :" << '\n';
    for (std::vector<int>::iterator i = pending.begin(); i != pending.end(); i++){
        std::cout << *i << '\n';
    }
    return (main);
}
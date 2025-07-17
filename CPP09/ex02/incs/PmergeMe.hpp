/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:58:51 by asayad            #+#    #+#             */
/*   Updated: 2025/07/16 10:42:57 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME
#define PMERGE_ME

#include<iostream>
#include<vector>
#include<set>
#include<exception>
#include<sstream>

class PmergeMe {
    private:
    public:
        std::vector<int> mainInit;
        PmergeMe();
        PmergeMe(const PmergeMe& p);
        PmergeMe& operator=(const PmergeMe& p);
        void parseInput(int ac, char**av);
        void FillVecs(int ac, char **av);
        ~PmergeMe();
        std::vector<int> sort(std::vector<int>& v);
        void Insert(std::vector<int>& m, std::vector<int>& p);
};


#endif
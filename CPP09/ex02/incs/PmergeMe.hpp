/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:58:51 by asayad            #+#    #+#             */
/*   Updated: 2025/07/30 09:16:07 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME
#define PMERGE_ME

#include<iostream>
#include<iomanip>
#include<deque>
#include<set>
#include<vector>
#include<utility>
#include<exception>
#include<sstream>
#include<algorithm>
#include <sys/time.h>
#include <ctime>

class PmergeMe{
	public:
		std::vector<int> vec;
		std::deque<int> deq;
		double pars_time;
		double vec_time;
		double deq_time;
		PmergeMe();
		PmergeMe(const PmergeMe& p);
		PmergeMe& operator=(const PmergeMe& p);
		~PmergeMe();
		void parsNdFill(int ac, char** av);
	};
	void sortVec(std::vector<int>& container);
	void sortMainPairs(std::vector<std::pair<int, int> >& v);
	void merge(std::vector<std::pair<int, int> >& lv, std::vector<std::pair<int, int> >& rv,
		std::vector<std::pair<int, int> >& v);
	void insertion(std::vector<int>& v, std::vector<std::pair<int, int> >& sortedPairs, std::vector<int>& rest);
	void sortDeq(std::deque<int>& container);
	void sortMainPairsD(std::deque<std::pair<int, int> >& v);
	void mergeD(std::deque<std::pair<int, int> >& lv, std::deque<std::pair<int, int> >& rv,
		std::deque<std::pair<int, int> >& v);
	void insertionD(std::deque<int>& v, std::deque<std::pair<int, int> >& sortedPairs, std::deque<int>& rest);
	template <typename T>
	void print(T& cont){
		for(typename T::iterator it = cont.begin(); it != cont.end(); it++)
				std::cout << *it << ' ';
		std::cout << '\n';
	}
	void printTime(const PmergeMe& p);
#endif
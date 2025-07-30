/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:02:46 by asayad            #+#    #+#             */
/*   Updated: 2025/07/30 09:17:22 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

PmergeMe::PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe& p){
	vec = p.vec;
	deq = p.deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& p){
	if (this != &p){
		vec = p.vec;
		deq = p.deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe(){
}

void PmergeMe::parsNdFill(int ac, char **av){
	std::istringstream in;
	std::vector<int> vecCpy;
	int a;
	for (int i = 1; i < ac; i++){
		in.clear();
		in.str(av[i]);
		while (in >> a){
			if (a < 0)
				throw (std::runtime_error("Invalid input !"));
			vec.push_back(a);
			deq.push_back(a);
		}
		if (in.fail() && !in.eof())
			throw (std::runtime_error("Invalid input !"));
	}
	vecCpy = vec;
	std::sort(vecCpy.begin(), vecCpy.end());
	if (std::unique(vecCpy.begin(), vecCpy.end()) != vecCpy.end())
		throw(std::runtime_error("Duplicate input !"));
	std::cout << "Before : ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
		std::cout << *it << ((it + 1) != vec.end() ? " " : "");
	}
	std::cout << '\n';
}

void sortVec(std::vector<int>& vec){
	
	std::vector<std::pair<int, int> > sortedPairs;
	std::vector<int> main;
	std::vector<int> rest;
	if (vec.size() % 2 != 0){
		rest.push_back(vec.back());
		vec.pop_back();
	}
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it += 2){
		if (it + 1 != vec.end()){
			if (*it < *(it + 1))
				sortedPairs.push_back(std::make_pair(*it, *(it + 1)));
			else
				sortedPairs.push_back(std::make_pair(*(it + 1), *it));
		}
	}
	sortMainPairs(sortedPairs);
	vec.clear();
	insertion(vec, sortedPairs, rest);
}

void sortMainPairs(std::vector<std::pair<int, int> >& v){
	if (v.size() <= 1)
		return ;
	std::vector<std::pair<int, int> > lv;
	std::vector<std::pair<int, int> > rv;
	lv.insert(lv.begin(), v.begin(), v.begin() + v.size() / 2);
	rv.insert(rv.begin(), v.begin() + v.size() / 2, v.end());
	sortMainPairs(lv);
	sortMainPairs(rv);
	merge(lv, rv, v);
}

void merge(std::vector<std::pair<int, int> >& lv, std::vector<std::pair<int, int> >& rv,
		std::vector<std::pair<int, int> >& v){
	int lv_s = lv.size();
	int rv_s = rv.size();
	int l_idx = 0, r_idx = 0, o = 0;
	while (l_idx < lv_s && r_idx < rv_s){
		if (lv[l_idx].second < rv[r_idx].second){
			v[o] = lv[l_idx];
			o++;
			l_idx++;
		}
		else if (lv[l_idx].second > rv[r_idx].second){
			v[o] = rv[r_idx];
			o++;
			r_idx++;
		}
	}
	while (l_idx < lv_s){
		v[o] = lv[l_idx];
		o++;
		l_idx++;
	}
	while (r_idx < rv_s){
		v[o] = rv[r_idx];
		o++;
		r_idx++;
	}
}

void insertion(std::vector<int>& main, std::vector<std::pair<int, int> >& sortedPairs, std::vector<int>& rest){
	std::vector<int> J;
	J.push_back(0);
	J.push_back(1);
	int s = sortedPairs.size();
	for (int i = 2; J[i - 1] <= s; i++){
		J.push_back(J[i - 1] + 2 * J[i - 2]);
	}
	for (std::vector<std::pair<int, int> >::iterator it = sortedPairs.begin();
	it != sortedPairs.end(); it++){
		if (it == sortedPairs.begin())
			main.push_back(it->first);
		main.push_back(it->second);
	}
	int pos = 0;
	for (size_t i = 1; i < J.size(); i++){
		pos = J[i];
		if (J[i] >= s)
			pos = s - 1;
		for (int j = pos; j > J[i - 1]; j--){
			int val = sortedPairs[j].first;
			std::vector<int>::iterator it = 
				std::upper_bound(main.begin(), main.end(), val);
			main.insert(it, val);
			if (j == 0)
				break;
		}
	}
	if (!rest.empty()){
		std::vector<int>::iterator it = std::upper_bound(main.begin(), main.end(), *rest.begin());
		main.insert(it, *rest.begin());
	}
}

void sortDeq(std::deque<int>& deq){
	std::deque<std::pair<int, int> > sortedPairs;
	std::deque<int> main;
	std::deque<int> rest;
	if (deq.size() % 2 != 0){
		rest.push_back(deq.back());
		deq.pop_back();
	}
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it += 2){
		if (it + 1 != deq.end()){
			if (*it < *(it + 1))
				sortedPairs.push_back(std::make_pair(*it, *(it + 1)));
			else
				sortedPairs.push_back(std::make_pair(*(it + 1), *it));
		}
	}
	sortMainPairsD(sortedPairs);
	deq.clear();
	insertionD(deq, sortedPairs, rest);
}

void sortMainPairsD(std::deque<std::pair<int, int> >& v){
	if (v.size() <= 1)
		return ;
	std::deque<std::pair<int, int> > lv;
	std::deque<std::pair<int, int> > rv;
	lv.insert(lv.begin(), v.begin(), v.begin() + v.size() / 2);
	rv.insert(rv.begin(), v.begin() + v.size() / 2, v.end());
	sortMainPairsD(lv);
	sortMainPairsD(rv);
	mergeD(lv, rv, v);
}

void mergeD(std::deque<std::pair<int, int> >& lv, std::deque<std::pair<int, int> >& rv,
		std::deque<std::pair<int, int> >& v){
	int lv_s = lv.size();
	int rv_s = rv.size();
	int l_idx = 0, r_idx = 0, o = 0;
	while (l_idx < lv_s && r_idx < rv_s){
		if (lv[l_idx].second < rv[r_idx].second){
			v[o] = lv[l_idx];
			o++;
			l_idx++;
		}
		else if (lv[l_idx].second > rv[r_idx].second){
			v[o] = rv[r_idx];
			o++;
			r_idx++;
		}
	}
	while (l_idx < lv_s){
		v[o] = lv[l_idx];
		o++;
		l_idx++;
	}
	while (r_idx < rv_s){
		v[o] = rv[r_idx];
		o++;
		r_idx++;
	}
}

void insertionD(std::deque<int>& main, std::deque<std::pair<int, int> >& sortedPairs, std::deque<int>& rest){
	std::deque<int> J;
	J.push_back(0);
	J.push_back(1);
	int s = sortedPairs.size();
	for (int i = 2; J[i - 1] <= s; i++){
		J.push_back(J[i - 1] + 2 * J[i - 2]);
	}
	for (std::deque<std::pair<int, int> >::iterator it = sortedPairs.begin();
	it != sortedPairs.end(); it++){
		if (it == sortedPairs.begin())
			main.push_back(it->first);
		main.push_back(it->second);
	}
	int pos = 0;
	for (size_t i = 1; i < J.size(); i++){
		pos = J[i];
		if (J[i] >= s)
			pos = s - 1;
		for (int j = pos; j > J[i - 1]; j--){
			int val = sortedPairs[j].first;
			std::deque<int>::iterator it = 
				std::upper_bound(main.begin(), main.end(), val);
			main.insert(it, val);
			if (j == 0)
				break;
		}
	}
	if (!rest.empty()){
		std::deque<int>::iterator it = std::upper_bound(main.begin(), main.end(), *rest.begin());
		main.insert(it, *rest.begin());
	}
}

void printTime(const PmergeMe& p){
	std::cout << "Pars " << std::fixed << std::setprecision(4) << p.pars_time << '\n';
	std::cout << "Vec time " << std::fixed << std::setprecision(4) << p.vec_time << '\n';
	std::cout << "Deq time " << std::fixed << std::setprecision(4) << p.deq_time << '\n';
	std::cout << "Time to process a range of " << p.vec.size() << " elements with std::vector : " 
		<< std::fixed << std::setprecision(5) << p.pars_time + p.vec_time << " us" << '\n';
	std::cout << "Time to process a range of " << p.deq.size() << " elements with std::deq    : " 
		<< std::fixed << std::setprecision(5) << p.pars_time + p.deq_time << " us" << '\n';
}
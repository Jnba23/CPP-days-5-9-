/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:58:51 by asayad            #+#    #+#             */
/*   Updated: 2025/07/21 22:31:08 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME
#define PMERGE_ME

#include<iostream>
#include<deque>
#include<vector>

template <typename T>
class PmergeMe{
	public:
		T container;
		PmergeMe();
		PmergeMe(const T& container);
		PmergeMe& operator=(const PmergeMe& p);
		~PmergeMe();
	};
	
	template <typename T>
	void sortContainer(T container);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:02:04 by asayad            #+#    #+#             */
/*   Updated: 2025/07/30 00:43:08 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PmergeMe.hpp>

int main(int ac, char **av){
	(void)av;
	if (ac > 1){
		try{
			struct timeval start_tv, end_tv;
			PmergeMe o;
			gettimeofday(&start_tv, NULL);
			o.parsNdFill(ac, av);
			gettimeofday(&end_tv, NULL);
			o.pars_time = static_cast<double>(end_tv.tv_sec - start_tv.tv_sec)
				* 1000000.0 + static_cast<double>(end_tv.tv_usec - start_tv.tv_usec);
			gettimeofday(&start_tv, NULL);
			sortVec(o.vec);
			gettimeofday(&end_tv, NULL);
			o.vec_time = static_cast<double>(end_tv.tv_sec - start_tv.tv_sec)
				* 1000000.0 + static_cast<double>(end_tv.tv_usec - start_tv.tv_usec);
			gettimeofday(&start_tv, NULL);
			sortDeq(o.deq);
			gettimeofday(&end_tv, NULL);
			o.deq_time = static_cast<double>(end_tv.tv_sec - start_tv.tv_sec)
				* 1000000.0 + static_cast<double>(end_tv.tv_usec - start_tv.tv_usec);
			std::cout << "After :  ";
			print(o.vec);
			printTime(o);
		} catch (const std::exception& e){
			std::cout << e.what() << '\n';
		}
	} else
		std::cout << "Not enough args !" << '\n';
	return 0;	
}
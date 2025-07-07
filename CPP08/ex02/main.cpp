/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:43:48 by asayad            #+#    #+#             */
/*   Updated: 2025/07/07 20:21:08 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <MutantStack.hpp>

int main()
{
    std::cout << "Mutant stack !" << '\n';
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "list !" << '\n';
    std::list<int> lista;
    lista.push_back(5);
    lista.push_back(17);
    std::cout << lista.back() << std::endl;
    lista.pop_back();
    std::cout << lista.size() << std::endl;
    lista.push_back(3);
    lista.push_back(5);
    lista.push_back(737);
    //[...]
    lista.push_back(0);
    std::list<int>::iterator lit = lista.begin();
    std::list<int>::iterator lite = lista.end();
    ++it;
    --it;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:22:17 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/17 15:48:18 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void listTest()
{
    std::cout << "===== Same Tests with List Container =====" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "[List] Last element: " << lst.back() << std::endl;

    lst.pop_back();
    std::cout << "[List] Size after pop: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;

    std::cout << "[List] Elements:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void mutantTest()
{
    std::cout << "===== MutantStack Tests =====" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "[MutantStack] Top element: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "[MutantStack] Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    std::cout << "[MutantStack] Elements:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

int main(void)
{
    mutantTest();
    listTest();
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:12:40 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/17 15:03:48 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack &other);
    MutantStack &operator=(const MutantStack &other);
    std::stack<T>::container_type::iterator begin();
    std::stack<T>::container_type::iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
    if (this == &other)
        return *this;
    std::stack<T>::operator=(other);
    return *this;
}

template <typename T>
std::stack<T>::container_type::iterator MutantStack::begin()
{
}

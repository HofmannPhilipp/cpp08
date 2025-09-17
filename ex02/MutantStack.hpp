/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:12:40 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/17 15:30:58 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() = default;
    ~MutantStack() = default;
    MutantStack(const MutantStack &other) = default;
    MutantStack &operator=(const MutantStack &other) = default;

    using iterator = typename std::stack<T>::container_type::iterator;
    iterator begin();
    iterator end();
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}
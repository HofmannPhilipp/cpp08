/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:44:00 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/17 16:48:34 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <array>
#include <cstddef>

template <size_t S>
class Span2
{
private:
    unsigned int N;
    std::array<int, S> arr;

public:
    Span2();
    Span2(int size);
    Span2(const Span2 &other);
    Span2 &operator=(const Span2 &other);
    ~Span2();
    void addNumber(int val);
    void addNumber(std::array<int>::iterator begin, std::array<int>::iterator end);
    int size();
    int shortestSpan();
    int longestSpan();
    std::array<int>::iterator begin();
    std::array<int>::iterator end();
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:27:04 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/18 13:18:01 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iostream>

Span::Span() : N(0)
{
}

Span::Span(unsigned int size) : N(size)
{
}

Span::Span(const Span &other) : N(other.N), v(other.v)
{
}

Span &Span::operator=(const Span &other)
{
    if (this == &other)
        return *this;
    N = other.N;
    v = other.v;
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(unsigned int val)
{
    if (v.size() >= N)
        throw std::length_error("Maximum container size reached");
    v.push_back(val);
}

void Span::addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
    if (v.size() + std::distance(begin, end) > N)
        throw std::length_error("Maximum container size reached");
    v.insert(v.end(), begin, end);
}

unsigned int Span::size()
{
    return N;
}

unsigned int Span::shortestSpan()
{
    if (v.size() < 2)
        throw std::length_error("Need at least two numbers to find a span");

    auto temp = this->v;
    std::sort(temp.begin(), temp.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();

    for (size_t i = 1; i < temp.size(); ++i)
    {
        unsigned int diff = temp[i] - temp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan()
{
    if (v.size() < 2)
        throw std::length_error("Need at least two numbers to find a span");

    auto [minIt, maxIt] = std::minmax_element(v.begin(), v.end());
    return *maxIt - *minIt;
}

std::vector<unsigned int>::iterator Span::begin()
{
    return v.begin();
}

std::vector<unsigned int>::iterator Span::end()
{
    return v.end();
}
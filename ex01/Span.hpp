/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:26:51 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/16 17:00:39 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>

class Span
{
private:
    unsigned int N;
    std::vector<unsigned int> v;

public:
    Span();
    Span(unsigned int size);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    void addNumber(unsigned int val);
    void addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
    unsigned int size();
    unsigned int shortestSpan();
    unsigned int longestSpan();
    std::vector<unsigned int>::iterator begin();
    std::vector<unsigned int>::iterator end();
};

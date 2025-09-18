/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:18:25 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/18 11:26:59 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>

void printSpan(Span &sp)
{
    for (auto it = sp.begin(); it != sp.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

void basicTest()
{
    std::cout << "=== Basic add & spans ===" << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Print Span:" << std::endl;
    printSpan(sp);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Print Span:" << std::endl;
    printSpan(sp);

    std::cout << "Longest  span: " << sp.longestSpan() << std::endl;
}

void containerFullTest()
{
    std::cout << "=== Exception: container full ===" << std::endl;
    Span sp(5);
    unsigned int nums[] = {1, 2, 3, 4, 5};
    for (unsigned int n : nums)
        sp.addNumber(n);

    try
    {
        sp.addNumber(42);
    }
    catch (const std::length_error &e)
    {
        std::cout << "Caught length_error: " << e.what() << std::endl;
    }
}

void rangeInsertTest()
{
    std::cout << "=== Range insert ===" << std::endl;
    Span sp(10);
    std::vector<unsigned int> nums = {1, 2, 3, 4, 5};
    sp.addNumber(nums.begin(), nums.end());
    std::cout << "Print Span:" << std::endl;
    printSpan(sp);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest  span: " << sp.longestSpan() << std::endl;
}

void notEnoughNumbersTest()
{
    std::cout << "=== Exception: not enough numbers for spans ===" << std::endl;
    Span sp(3);
    sp.addNumber(42);
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::length_error &e)
    {
        std::cout << "Caught length_error: " << e.what() << std::endl;
    }
}

void bigTest()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::cout << "=== Test with 10,000 numbers ===" << std::endl;

    Span sp(10000);
    for (int i = 0; i < 10000; ++i)
    {
        sp.addNumber(std::rand());
    }

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest  span: " << sp.longestSpan() << std::endl;
}

int main()
{
    try
    {
        basicTest();
        containerFullTest();
        rangeInsertTest();
        notEnoughNumbersTest();
        bigTest();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}
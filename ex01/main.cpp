/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:18:25 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/16 17:16:46 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>

void basicTest()
{
    std::cout << "=== Basic add & spans ===" << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest  span: " << sp.longestSpan() << std::endl;
}

void containerFullTest()
{
    std::cout << "=== Exception: container full ===" << std::endl;
    Span sp(5);
    for (int n : {1, 2, 3, 4, 5})
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
    Span sp2(10);
    std::vector<unsigned int> nums = {1, 2, 3, 4, 5};
    sp2.addNumber(nums.begin(), nums.end());

    std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest  span: " << sp2.longestSpan() << std::endl;
}

void notEnoughNumbersTest()
{
    std::cout << "=== Exception: not enough numbers for spans ===" << std::endl;
    Span sp3(3);
    sp3.addNumber(42);
    try
    {
        std::cout << sp3.shortestSpan() << std::endl;
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

    Span big(10000);
    for (int i = 0; i < 10000; ++i)
    {
        big.addNumber(std::rand());
    }

    std::cout << "Shortest span: " << big.shortestSpan() << std::endl;
    std::cout << "Longest  span: " << big.longestSpan() << std::endl;
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
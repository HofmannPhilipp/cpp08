/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:49:33 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/11 14:24:07 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v = {10, 20, 30};
    std::list<int> l = {5, 15, 25};

    try
    {
        auto it = easyfind(v, 20);
        std::cout << "Found: " << *it << "\n";

        auto it2 = easyfind(l, 15);
        std::cout << "Found: " << *it2 << "\n";

        it = easyfind(v, 99); // throws exception
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}
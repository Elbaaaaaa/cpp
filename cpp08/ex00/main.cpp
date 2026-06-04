/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:40:13 by ebella            #+#    #+#             */
/*   Updated: 2026/06/04 13:02:47 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::cout << "--- Test with std::vector ---\n" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try {
        std::cout << "search 20 : ";
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout <<  "the value : " << *it << ", was found !" << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    try {
        std::cout << "search 99 (doesnt exist) : ";
        easyfind(vec, 99);
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test with std::list ---\n" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        std::cout << "search 3 : ";
        std::list<int>::iterator it = easyfind(lst, 3);
        std::cout << "The value : " << *it << ", was found !" << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
    }

    return 0;
}
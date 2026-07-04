#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main()
{
    std::cout << "=== TEST 1 ===" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 2 ===" << std::endl;
    try {
        Span sp2(10);
        std::vector<int> myVec;
        myVec.push_back(100);
        myVec.push_back(200);
        myVec.push_back(300);
        
        sp2.addNumber(myVec.begin(), myVec.end());
        std::cout << "Size: 3. Longest span (300-100) : " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 3 : 15 000 random numbers ===" << std::endl;
    try {
        unsigned int size = 15000;
        Span spBig(size);
        std::vector<int> bigData;
        
        std::srand(std::time(NULL));
        for (unsigned int i = 0; i < size; ++i)
            bigData.push_back(std::rand());

        spBig.addNumber(bigData.begin(), bigData.end());

        std::cout << "Shortest Span: " << spBig.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << spBig.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TEST 4 ===" << std::endl;
    
    std::cout << "Test Span too small (0 or 1 elements) : " << std::endl;
    try {
        Span spSmall(5);
        spSmall.addNumber(42);
        spSmall.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Test Span full: " << std::endl;
    try {
        Span spFull(2);
        spFull.addNumber(1);
        spFull.addNumber(2);
        spFull.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
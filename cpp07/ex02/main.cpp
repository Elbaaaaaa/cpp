#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "Testing Default Constructor " << std::endl;
    Array<int> emptyArray;
    std::cout << "emptyArray size: " << emptyArray.size() << std::endl;

    std::cout << "\nTesting initilized Constructor " << std::endl;
    Array<int> intArray(5);
    std::cout << "intArray size: " << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i * 10;
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    std::cout << "\nTesting Templates with std::string " << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "42";
    for (unsigned int i = 0; i < stringArray.size(); i++) {
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
    }

    std::cout << "\nTesting Copy Constructor (Deep Copy) " << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "Modifying copyArray[0] to 999..." << std::endl;
    copyArray[0] = 999;
    std::cout << "intArray[0]: " << intArray[0] << " (Should be 0, unchanged)" << std::endl;
    std::cout << "copyArray[0]: " << copyArray[0] << " (Should be 999, modified)" << std::endl;

    std::cout << "\nTesting Assignment Operator (Deep Copy) " << std::endl;
    Array<int> assignArray;
    assignArray = intArray;
    std::cout << "Modifying assignArray[1] to 888..." << std::endl;
    assignArray[1] = 888;
    std::cout << "intArray[1]: " << intArray[1] << " (Should be 10, unchanged)" << std::endl;
    std::cout << "assignArray[1]: " << assignArray[1] << " (Should be 888, modified)" << std::endl;

    std::cout << "\nTesting Out of Bounds Exceptions " << std::endl;
    try {
        std::cout << "Trying to access intArray[5] (size is 5)..." << std::endl;
        std::cout << intArray[5] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "Trying to access intArray[-1]..." << std::endl;
        std::cout << intArray[-1] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}




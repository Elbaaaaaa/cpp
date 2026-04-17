#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T const & x) {
    std::cout << x << " ";
}

void increment(int & x) {
    x++;
}

int main() {
    int tab[] = {1, 2, 3, 4, 5};
    std::cout << "original tab : ";
    iter(tab, 5, printElement<int>);
    std::cout << std::endl;

    iter(tab, 5, increment);
    std::cout << "after increment : ";
    iter(tab, 5, printElement<int>);
    std::cout << std::endl;

    const int cTab[] = {10, 20, 30};
    std::cout << "const tab : ";
    iter(cTab, 3, printElement<int>);
    std::cout << std::endl;

    std::string strings[] = {"Hello", "World", "!"};
    std::cout << "strings tab : ";
    iter(strings, 3, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
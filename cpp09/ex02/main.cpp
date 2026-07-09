#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No sequence provided. Usage: ./PmergeMe [positive integers...]" << std::endl;
        return 1;
    }

    PmergeMe sorter;

    try
    {
        sorter.initArgs(argc, argv);

        clock_t startVec = clock();

        sorter.fordJonsonSort(sorter.getVec()); 
        clock_t endVec = clock();
        
        double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

        clock_t startDeq = clock();
        sorter.fordJonsonSort(sorter.getDeq());
        clock_t endDeq = clock();

        double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;


        sorter.printFinalResult();


        std::cout << "Time to process a range of " << argc - 1 
                  << " elements with std::vector : " << std::fixed << std::setprecision(5) 
                  << timeVec << " us" << std::endl;

        std::cout << "Time to process a range of " << argc - 1 
                  << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
                  << timeDeq << " us" << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
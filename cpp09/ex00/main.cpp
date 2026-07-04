#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc;

        try {
            btc.LoadDatabase("data.csv");
        }
        catch (const std::exception &e) {
            std::cerr << "Error: Internal database failure: " << e.what() << std::endl;
            return 1;
        }
        btc.ProcessInput(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
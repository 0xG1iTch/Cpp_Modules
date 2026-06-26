#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
    if(ac != 2)
    {
        std::cout << "Error: Program must Take a file as an argument" << std::endl;
        std::cout << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange btc;
        btc.input_processing(av[1]);
    }
    catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
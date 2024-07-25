# include <iostream>
# include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "A file argument is expected." << std::endl;
        return (1);
    }

    std::string file = argv[1];

    BitcoinExchange btc = BitcoinExchange(file);

    return (0);
}
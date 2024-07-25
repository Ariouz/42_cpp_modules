#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <map>
# include <ctime>
# include <iomanip>
# include <fstream>
# include <algorithm>

class BitcoinExchange
{
    public:
        BitcoinExchange(const std::string& infilename);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        std::multimap<std::time_t, float>   getValues() const;
        std::string                         getInfileName() const;

    private:
        BitcoinExchange();

        std::ifstream                       _data_file;
        std::ifstream                       _infile;
        std::multimap<std::time_t, float>   _values;
        std::multimap<std::time_t, float>   _infile_values;
        std::string                         _infilename;

        int     parseValues(const std::string& filename, std::ifstream& file, std::multimap<std::time_t, float>& container, const std::string& delimiter);
        int     checkInFile() const;
        void    printValues() const;
};

#endif
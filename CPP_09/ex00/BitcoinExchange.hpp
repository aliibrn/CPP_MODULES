#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cctype>

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange{
    private: 
        std::map<std::string, std::string> data;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& copy);
        ~BitcoinExchange();

        void    GetResults(std::string line);
        void    SetData(std::string line);

        bool    isValidDate(const std::string& date) const;
        bool    hasValidExtension(const std::string& filename);
        bool    parsePipeLine(const std::string &line, std::string &key, std::string &value);
        
        int     line;
};
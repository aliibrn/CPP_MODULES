#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cctype>

class RPN{
    private:
        std::vector<std::string> numbers;

    public:
        RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& copy);
        ~RPN();

        void parse_numbers(std::string line);
        void RPN_CALCULATIONS();
};
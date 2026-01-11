#include "RPN.hpp"


RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN& copy){
    if(this != &copy){
        numbers = copy.numbers;
    }
    return *this;
}

RPN::RPN(const RPN& copy): numbers(copy.numbers){

}

void RPN::parse_numbers(std::string line)
{

    std::istringstream iss(line);
    std::string token;

    while (iss >> token)
    {
        if (token.length() == 1 && std::isdigit(token[0]))
            numbers.push_back(token);
        else if (token == "+" || token == "-" || token == "*" || token == "/")
            numbers.push_back(token);
        else
        {
            std::cerr << "Error: Invalid token in RPN expression: " << std::endl;
            throw 1;
        }
    }
}

void RPN::RPN_CALCULATIONS()
{
    std::vector<int> stack;

    for (size_t i = 0; i < numbers.size(); ++i)
    {
        const std::string &token = numbers[i];

        if (token.length() == 1 && std::isdigit(token[0]))
        {
            stack.push_back(std::atoi(token.c_str()));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: Not enough operands for operation." << std::endl;
                throw 1;
            }

            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();
            int result = 0;

            if (token == "+")
                result = a + b;
            else if (token == "-")
                result = a - b;
            else if (token == "*")
                result = a * b;
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cerr << "Error: Division by zero." << std::endl;
                    throw 1;
                }
                result = a / b;
            }
            stack.push_back(result);
        }
        else
        {
            std::cerr << "Error: Unexpected token." << std::endl;
            throw 1;
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error: Invalid RPN expression. Final stack size: " << stack.size() << std::endl;
        throw 1;
    }
    std::cout << stack[0] << std::endl;
}

#include "Harl.hpp"
#include "Harl.hpp"
#include <string>

Harl::Harl() {}


void Harl::debug(void)
{
    std::cout << "DEBUG :" << std::endl
              << "  debug message " << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO :" << std::endl 
            << "   info message " << std::endl;
}

void Harl::warning(void)
{
    std::cout <<  "WARNING :" << std::endl
              << "    warning message " << std::endl;
}

void Harl::error(void)
{
    std::cout << "ERROR :" << std::endl
              << "    error message " << std::endl;
}

void Harl::complain(std::string level)
{

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    while (i < 4 && levels[i] != level)
        i++;
    switch (i)
    {
        case 4:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    default:
        while (i < 4)
        {
            (this->*functions[i])();
                i++;
        }
    }
}
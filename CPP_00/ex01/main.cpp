#include "PhoneBook.hpp"
#include <stdio.h>

int main()
{
    PhoneBook phonebook;

    while (1)
    {
        int check;
        std::cout << YELLOW << "ENTER COMMAND : " << COLOR_RESET;
        std::string input;
        std::getline(std::cin, input);
        if (!std::cin)
            break;
        if (input == "ADD")
        {
            check = phonebook.add_contact();
            if (check == -1)
                break;
            if (check == -2)
            {
                std::cout << RED << "ERROR EMPTY FIELD" << COLOR_RESET << std::endl;
                continue;
            }
            std::cout << GREEN << "contact ADDED SUCCESSFULLY" << COLOR_RESET << std::endl;
        }
        else if (input == "SEARCH")
        {
            phonebook.search_contact();
            std::cout << YELLOW << "ENTER INDEX : " << COLOR_RESET;
            std::string input;
            std::getline(std::cin, input);
            if (!std::cin)
                break;
            const char *cstr = input.c_str();
            int num = atoi(cstr);
            if (num < 9 && num > 0)
                phonebook.print_contact_info(num);
            else
                std::cout << RED << "INVALID INDEX" << COLOR_RESET << std::endl;
        }
        else if (input == "EXIT")
        {
            break;
        }
        else
            std::cout << RED << "INVALID INPUT" << COLOR_RESET << std::endl;
    }
}

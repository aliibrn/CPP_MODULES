#include "PhoneBook.hpp"
#include <stdio.h>

int Contact::add_info()
{
    std::string firstname, lastname, nickname, phonenumber, darkestsec;
    std::cout << GREEN << "Please enter all contact details." << std::endl;
    std::cout << BLUE << "FIRST NAME : " << COLOR_RESET;
    std::getline(std::cin, firstname);
    if (!std::cin)
        return (-1);
    if(firstname.empty())
            return (-2);
    std::cout << BLUE << "LAST NAME : " << COLOR_RESET;
    std::getline(std::cin, lastname);
    if (!std::cin)
        return (-1);
    if(lastname.empty())
            return (-2);
    std::cout << BLUE << "NICK NAME : " << COLOR_RESET;
    std::getline(std::cin, nickname);
    if (!std::cin)
        return (-1);
    if(nickname.empty())
            return (-2);
    std::cout << BLUE << "PHONE NUMBER : " << COLOR_RESET;
    std::getline(std::cin, phonenumber);
    if (!std::cin)
        return (-1);
    if(phonenumber.empty())
            return (-2);
    std::cout << BLUE << "DARKEST SECRET : " << COLOR_RESET;
    std::getline(std::cin, darkestsec);
    if (!std::cin)
        return (-1);
    if(darkestsec.empty())
            return (-2);
    this->info.firstname = firstname;
    this->info.lastname = lastname;
    this->info.nickname = nickname;
    this->info.phonenumber = phonenumber;
    this->info.darkestsecret = darkestsec;
    return (0);
}

void Contact::show_all_info(int index)
{
    index += 1;
    std::ostringstream oss;
    oss << index;
    std::string str_index = oss.str();
    std::cout << "|" << std::setw(10) << str_index;
    std::string fields[] = {this->info.firstname, this->info.lastname, this->info.nickname};

    for (int i = 0; i < 3; i++)
    {
        std::string field = fields[i];
        int len = field.length();
        if (len > 10)
        {
            field = field.substr(0, 9) + ".";
        }
        std::cout << "|" << std::setw(10) << field;
    }
    std::cout << "|" << std::endl;
}

void Contact::print_info()
{
    std::cout << CYAN << "FIRST NAME : " + this->info.firstname << std::endl;
    std::cout <<  "LAST NAME : " + this->info.lastname << std::endl;
    std::cout <<  "NICK NAME : " + this->info.nickname << std::endl;
    std::cout <<  "PHONE NUMBER : " + this->info.phonenumber << std::endl;
    std::cout <<  "DARKEST SECRET : " + this->info.darkestsecret << COLOR_RESET << std::endl;
}
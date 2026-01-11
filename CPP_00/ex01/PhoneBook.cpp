#include "PhoneBook.hpp"
#include <stdio.h>

PhoneBook::PhoneBook(): i(0)
{
        std::cout << MAGENTA << "Welcome To Phone book" << COLOR_RESET << std::endl;
        std::cout << MAGENTA << "The program only accepts ADD, SEARCH and EXIT." << COLOR_RESET << std::endl;
} 

int    PhoneBook::add_contact()
{
    int check = this->contact[i].add_info();
    if(check == -1 || check == -2)
        return (check);
    if(i < 7)
        this->i++;
    return (0);
}

void    PhoneBook::search_contact(){
    int y = 0;
    while(y < 8)
    {
        this->contact[y].show_all_info(y);
        y++;
    }
}

void    PhoneBook::print_contact_info(int i)
{
    i -= 1;
    if(i > this->i)
        std::cout << RED <<  "field not found" <<  COLOR_RESET << std::endl ;
    else
    {  
        this->contact[i].print_info();
    }
}
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
    Contact contact[8];
    int i;
    public:
    PhoneBook();
    int     add_contact();
    void    search_contact();
    void    print_contact_info(int i);
};

#endif
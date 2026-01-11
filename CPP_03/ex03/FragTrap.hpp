#ifndef FRAGTRAP_CPP
#define FRAGTRAP_CPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap{
    public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& copie);
    FragTrap& operator=(const FragTrap& copie);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif
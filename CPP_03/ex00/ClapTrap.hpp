#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define RESET   "\033[0m"

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"


class  ClapTrap{
    
    private:
        
        std::string name;
        int Hit_points;
        int Energy_points;
        int Attack_damage;
    
    public:
        
        ClapTrap();
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap& copy);
        ClapTrap& operator=(const ClapTrap &copy);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
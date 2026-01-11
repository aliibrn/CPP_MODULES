#include "ClapTrap.hpp"


ClapTrap::ClapTrap(): name("default"), 
                      Hit_points(10),
                      Energy_points(10),
                      Attack_damage(0)
{
    std::cout << CYAN << "ClapTrap " << RESET
                << RED <<  name  << RESET
                << MAGENTA <<  " | Hits point: " << Hit_points <<  RESET 
                << BLUE << " | Energy points: " << Energy_points <<  RESET
                <<  YELLOW << " | Attack damage:" << Attack_damage << RESET 
                << std::endl;
}



ClapTrap::ClapTrap(const std::string &e_name) : name(e_name),
                                                Hit_points(10),
                                                Energy_points(10),
                                                Attack_damage(0)

{
    std::cout << CYAN << "ClapTrap " << RESET
                << RED <<  name  << RESET
                << MAGENTA <<  " | Hits point: " << Hit_points <<  RESET 
                << BLUE << " | Energy points: " << Energy_points <<  RESET
                <<  YELLOW << " | Attack damage:" << Attack_damage << RESET 
                << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copy){
    
    std::cout << GREEN << "copy assigmenent called" << RESET << std::endl;
    if(this != &copy)
    {
        name = copy.name;
        Hit_points = copy.Hit_points;
        Attack_damage = copy.Attack_damage;
        Energy_points = copy.Energy_points;
    }
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap& copy){
    std::cout << GREEN << "copy constructor called" << RESET << std::endl;
    *this = copy;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    
    Hit_points -= amount;
    if(Hit_points <= 0)
    {
        Hit_points = 0;
        std::cout << RED << name << " is dead" <<  RESET << std::endl;
        return;
    }
    std::cout << CYAN << "ClapTrap " <<  RESET 
               << RED << name << RESET  
               << GREEN  << " take amount " << amount << " of damage " << RESET
               << MAGENTA << "| Hits points : "  << Hit_points << std::endl;
        
}

void ClapTrap::attack(const std::string &target)
{
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points -= 1;
        std::cout << CYAN << "ClapTrap " << RESET
                   << RED <<  name  << RESET
                    << GREEN << " attacks " << target << RESET
                    << YELLOW << " causing " << Attack_damage << " points of damage " << RESET
                    << MAGENTA << "| Energy points: " << Energy_points << RESET << std::endl;
    }
    else
        std::cout << BLUE << "ClapTrap " << name << " cant do anything" <<  RESET << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    unsigned int check = 0;

    if (Energy_points > 0 && Hit_points > 0 && amount > 0)
    {
        Energy_points -= 1;
        if ((Hit_points + amount) > 10)
        {
            check = 10 - Hit_points;
            amount = check;
        }
        Hit_points += amount;
        std::cout << CYAN << "ClapTrap " << RESET
                    << RED << name << RESET
                     << GREEN << " repaired amount of " << amount << RESET
                     << MAGENTA  << " | Hit point : " << Hit_points << RESET << std::endl;
    }
    else
        std::cout << BLUE << "ClapTrap " << name << " cant do anything" <<  RESET << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << CYAN << "ClapTrap " << RESET
                << RED <<  name
                <<  " Destructor" << RESET << std::endl;
}

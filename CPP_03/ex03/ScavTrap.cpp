#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    Hit_points = 100;
    Attack_damage = 20;
    Energy_points = 50;
    std::cout << "ScavTrap "
              << RED << this->name << RESET
              << MAGENTA << " | Hits point: " << Hit_points << RESET
              << BLUE << " | Energy points: " << Energy_points << RESET
              << YELLOW << " | Attack damage:" << Attack_damage << RESET
              << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    Hit_points = 100;
    Attack_damage = 20;
    Energy_points = 50;
    std::cout << "ScavTrap "
              << RED << this->name << RESET
              << MAGENTA << " | Hits point: " << Hit_points << RESET
              << BLUE << " | Energy points: " << Energy_points << RESET
              << YELLOW << " | Attack damage:" << Attack_damage << RESET
              << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copie)
{
    if (this != &copie)
    {
        ClapTrap::operator=(copie);
    }
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap &copie)
{
    std::cout << GREEN << "copy constructor called" << RESET << std::endl;
    *this = copie;
}

void ScavTrap::attack(const std::string& target){
    if (Energy_points > 0 && Hit_points > 0)
    {
        Energy_points -= 1;
        std::cout << CYAN << "ScavTrap " << RESET
                   << RED <<  name  << RESET
                    << GREEN << " attacks " << target << RESET
                    << YELLOW << " causing " << Attack_damage << " points of damage " << RESET
                    << MAGENTA << "| Energy points: " << Energy_points << RESET << std::endl;
    }
    else
        std::cout << BLUE << "ScavTrap " << name << " cant do anything" <<  RESET << std::endl;
}


ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap "
              << RED << name
              << " Destructor" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << GREEN << "ScavTrap " << name << " is now in Gate keeper mode" << RESET << std::endl;
}
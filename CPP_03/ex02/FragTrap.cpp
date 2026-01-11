#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    Hit_points = 100;
    Attack_damage = 30;
    Energy_points = 100;
    std::cout << YELLOW << "FragTrap " << RESET
              << RED << name << RESET
              << MAGENTA << " | Hits point: " << Hit_points << RESET
              << BLUE << " | Energy points: " << Energy_points << RESET
              << YELLOW << " | Attack damage:" << Attack_damage << RESET
              << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    Hit_points = 100;
    Attack_damage = 30;
    Energy_points = 100;
    std::cout << YELLOW << "FragTrap " << RESET
              << RED << this->name << RESET
              << MAGENTA << " | Hits point: " << Hit_points << RESET
              << BLUE << " | Energy points: " << Energy_points << RESET
              << YELLOW << " | Attack damage:" << Attack_damage << RESET
              << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copie)
{
    std::cout << GREEN << "copy assignement called" << RESET << std::endl;
    if (this != &copie)
    {
        ClapTrap::operator=(copie);
    }
    return *this;
}

FragTrap::FragTrap(const FragTrap &copie)
{
    std::cout << GREEN << "copy constructor called" << RESET << std::endl;
    *this = copie;
}

FragTrap::~FragTrap()
{
    std::cout << YELLOW << "FragTrap " << RESET
              << RED << name
              << " Destructor" << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << GREEN << "FragTrap " << name << " positive high fives request on the standard output." << RESET << std::endl;
}

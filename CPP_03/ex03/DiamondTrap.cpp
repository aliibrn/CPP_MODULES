#include "DiamondTrap.hpp"



DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), 
                            name("default") 
{
    this->Hit_points = FragTrap::Hit_points;      
    this->Energy_points = ScavTrap::Energy_points; 
    this->Attack_damage = FragTrap::Attack_damage;
    std::cout << "DiamondTrap " 
                << RED <<  this->name  << RESET
                << MAGENTA <<  " | Hits point: " << Hit_points <<  RESET 
                << BLUE << " | Energy points: " << Energy_points <<  RESET
                <<  YELLOW << " | Attack damage:" << Attack_damage << RESET 
                << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), 
                                            name(name){
    this->Hit_points = FragTrap::Hit_points;      
    this->Energy_points = ScavTrap::Energy_points; 
    this->Attack_damage = FragTrap::Attack_damage;
    std::cout << "DiamondTrap "
                << RED <<  name  << RESET
                << MAGENTA <<  " | Hits point: " << Hit_points <<  RESET 
                << BLUE << " | Energy points: " << Energy_points <<  RESET
                <<  YELLOW << " | Attack damage:" << Attack_damage << RESET 
                << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &copie){
    std::cout << GREEN << "copy assigmenent called" << RESET << std::endl;
    if(this != &copie){
        name = copie.name;
        Hit_points = copie.Hit_points;
        Energy_points = copie.Energy_points;
        Attack_damage = copie.Attack_damage;
    }
    return *this;
}

void DiamondTrap::whoAmI() {
        std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

DiamondTrap::DiamondTrap(const DiamondTrap& copie){
    std::cout << GREEN << "copy constructor called" << RESET << std::endl;
    *this = copie;
}

DiamondTrap::~DiamondTrap(){
    std::cout << GREEN << "DiamondTrap " << this->name << " destructor!" << RESET <<std::endl;
}
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap &operator=(const ScavTrap& copie);
        ScavTrap(const ScavTrap& copie);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();
};

#endif
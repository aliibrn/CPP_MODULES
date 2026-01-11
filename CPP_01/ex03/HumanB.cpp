#include "HumanB.hpp"


HumanB::HumanB(const std::string& name):name(name),weapon(NULL){

}


void HumanB::attack()
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " don't have a weapon "<< std::endl;

}

void HumanB::setWeapon(Weapon& _weapon)
{
    weapon = &_weapon;
}
#include "HumanA.hpp"

void    HumanA::attack(){
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::HumanA(const std::string &input_name, Weapon &input_weapon): name(input_name), weapon(input_weapon){}

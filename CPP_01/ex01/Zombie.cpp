#include "Zombie.hpp"

void Zombie::announce(void){
    std::cout << name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(void){}

Zombie::~Zombie(){
    std::cout << name << std::endl;
}

void    Zombie::set_name(std::string name){
    this->name = name;
}

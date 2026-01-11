#include "Weapon.hpp"

Weapon::Weapon(){
    type = "";
};

Weapon::Weapon(const std::string &input_type):type(input_type){}


const std::string &Weapon::getType( ) const{
    return this->type;
}

void    Weapon::setType(const std::string &type){
    this->type = type;
}
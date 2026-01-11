#include "Classes.hpp"

WrongAnimal::WrongAnimal(): type("default"){
    std::cout <<  MAGENTA << "default Constructor OF WrongAnimal" 
               << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy){
    std::cout << MAGENTA << "copy Constructor OF WrongAnimal" 
                << RESET << std::endl;
    *this = copy;
}   

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy){
    std::cout << MAGENTA << "Copy Assignement OF WrongAnimal" 
                << RESET << std::endl;
    if(this != &copy){
        type = copy.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << MAGENTA << "Destructor OF WrongAnimal" 
                << RESET << std::endl;
}

std::string WrongAnimal::getType() const{
    return type;
}

void WrongAnimal::makeSound() const{
    std::cout << MAGENTA << "???" << RESET <<std::endl;
}
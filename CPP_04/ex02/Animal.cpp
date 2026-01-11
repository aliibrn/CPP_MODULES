#include "Classes.hpp"

AAnimal::AAnimal(): type("default"){
    std::cout <<  RED << "default Constructor OF AAnimal" 
               << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy){
    std::cout << RED << "copy Constructor OF AAnimal" 
                << RESET << std::endl;
    *this = copy;
}   

AAnimal& AAnimal::operator=(const AAnimal& copy){
    std::cout << RED << "Copy Assignement OF AAnimal" 
                << RESET << std::endl;
    if(this != &copy){
        type = copy.type;
    }
    return *this;
}

AAnimal::~AAnimal(){
    std::cout << RED << "Destructor OF AAnimal" 
                << RESET << std::endl;
}

std::string AAnimal::getType() const{
    return type;
}

// void AAnimal::makeSound() const{
//     std::cout << RED << "???" << RESET <<std::endl;
// }




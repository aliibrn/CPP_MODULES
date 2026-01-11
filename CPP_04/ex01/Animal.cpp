#include "Classes.hpp"

Animal::Animal(): type("default"){
    std::cout <<  RED << "default Constructor OF ANIMAL" 
               << RESET << std::endl;
}

Animal::Animal(const Animal& copy){
    std::cout << RED << "copy Constructor OF ANIMAL" 
                << RESET << std::endl;
    *this = copy;
}   

Animal& Animal::operator=(const Animal& copy){
    std::cout << RED << "Copy Assignement OF ANIMAL" 
                << RESET << std::endl;
    if(this != &copy){
        type = copy.type;
    }
    return *this;
}

Animal::~Animal(){
    std::cout << RED << "Destructor OF ANIMAL" 
                << RESET << std::endl;
}

std::string Animal::getType() const{
    return type;
}

void Animal::makeSound() const{
    std::cout << RED << "???" << RESET <<std::endl;
}




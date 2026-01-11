#include "Classes.hpp"

Dog::Dog(){
    type = "Dog";
    std::cout <<  YELLOW << "default Constructor OF Dog" 
               << RESET << std::endl;
}


Dog::Dog(const Dog& copy){
    std::cout << YELLOW << "copy Constructor OF Dog" 
                << RESET << std::endl;
    *this = copy;
}   

Dog& Dog::operator=(const Dog& copy){
    std::cout << YELLOW << "Copy Assignement OF Dog" 
                << RESET << std::endl;
    if(this != &copy){
        type = copy.type;
    }
    return *this;
}

Dog::~Dog(){
    std::cout << YELLOW << "Destructor OF Dog" 
                << RESET << std::endl;
}


void Dog::makeSound() const{
    std::cout << YELLOW << "Haw Haw " 
            << RESET << std::endl;
}
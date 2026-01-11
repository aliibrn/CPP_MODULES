#include "Classes.hpp"

Dog::Dog(): brain(new Brain()){
    type = "Dog";
    std::cout <<  YELLOW << "default Constructor OF Dog" 
               << RESET << std::endl;
}


Dog::Dog(const Dog& copy): AAnimal(copy), brain(new Brain(*copy.brain)){
    std::cout << YELLOW << "copy Constructor OF Dog" 
                << RESET << std::endl;
}   

Dog& Dog::operator=(const Dog& copy){
    std::cout << YELLOW << "Copy Assignement OF Dog" 
                << RESET << std::endl;
    if(this != &copy){
        AAnimal::operator=(copy);
        *brain = *copy.brain;
    }
    return *this;
}

Dog::~Dog(){
    std::cout << YELLOW << "Destructor OF Dog" 
                << RESET << std::endl;
    if(brain)
        delete brain;
}


void Dog::makeSound() const{
    std::cout << YELLOW << "Haw Haw " 
            << RESET << std::endl;
}
#include "Classes.hpp"

Cat::Cat(): brain(new Brain()){
    type = "Cat";
    std::cout <<  GREEN << "default Constructor OF Cat" 
               << RESET << std::endl;
}

Cat::Cat(const Cat& copy): AAnimal(copy), brain(new Brain(*copy.brain)){
    std::cout << GREEN << "copy Constructor OF Cat" 
                << RESET << std::endl;
}   

Cat& Cat::operator=(const Cat& copy){
    std::cout << GREEN << "Copy Assignement OF Cat" 
                << RESET << std::endl;
    if(this != &copy){
        AAnimal::operator=(copy);
        *brain = *copy.brain;
    }
    return *this;
}

Cat::~Cat(){
    std::cout << GREEN << "Destructor OF Cat" 
                << RESET << std::endl;
    if(brain)
        delete brain;
}


void Cat::makeSound() const{
    std::cout << GREEN << "Moeeeeeeeeeeeeew Moeeeeeeeeeeeeeeeeeeeeeeeew " 
            << RESET << std::endl;
}
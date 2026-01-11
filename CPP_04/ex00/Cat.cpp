#include "Classes.hpp"

Cat::Cat(){
    type = "Cat";
    std::cout <<  GREEN << "default Constructor OF Cat" 
               << RESET << std::endl;
}

Cat::Cat(const Cat& copy){
    std::cout << GREEN << "copy Constructor OF Cat" 
                << RESET << std::endl;
    *this = copy;
}   

Cat& Cat::operator=(const Cat& copy){
    std::cout << GREEN << "Copy Assignement OF Cat" 
                << RESET << std::endl;
    if(this != &copy){
        type = copy.type;
    }
    return *this;
}

Cat::~Cat(){
    std::cout << GREEN << "Destructor OF Cat" 
                << RESET << std::endl;
}


void Cat::makeSound() const{
    std::cout << GREEN << "Moeeeeeeeeeeeeew Moeeeeeeeeeeeeeeeeeeeeeeeew " 
            << RESET << std::endl;
}
#include "Classes.hpp"

WrongCat::WrongCat(){
    type = "Cat";
    std::cout << CYAN << "default Constructor OF WrongCat" 
               << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy){
    std::cout <<CYAN << "copy Constructor OF WrongCat" 
                << RESET << std::endl;
    *this = copy;
}   

WrongCat& WrongCat::operator=(const WrongCat& copy){
    std::cout <<CYAN << "Copy Assignement OF WrongCat" 
                << RESET << std::endl;
    if(this != &copy){
        type = copy.type;
    }
    return *this;
}

WrongCat::~WrongCat(){
    std::cout <<CYAN << "Destructor OF WrongCat" 
                << RESET << std::endl;
}


void WrongCat::makeSound() const{
    std::cout <<CYAN << "Moeeeeeeeeeeeeew Moeeeeeeeeeeeeeeeeeeeeeeeew " 
            << RESET << std::endl;
}
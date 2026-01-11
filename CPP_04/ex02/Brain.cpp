#include "Classes.hpp"

Brain::Brain(){
    std::cout << BLUE << "Constructor Brain" << std::endl;
}

Brain::Brain(const Brain& copy){
    std::cout << BLUE << "Copy Constructor Brain" << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain &copy){
    std::cout << BLUE << "Copy assignement Brain" << std::endl;
    if(this != &copy)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = copy.ideas[i];
    }
    return *this;
}

Brain::~Brain(){
    std::cout << BLUE << "Destructor Brain" << std::endl;
}
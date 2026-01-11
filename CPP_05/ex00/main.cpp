#include "Bureaucrat.hpp"

int main() {
    Bureaucrat* t1 = NULL;  
    try {
        t1 = new Bureaucrat("hamouda", 150);
        t1->incrementGrade();
        t1->decrementGrade(); 
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl; 
        return 1;
    }
    std::cout << *t1 << std::endl;  
    delete t1; 
}
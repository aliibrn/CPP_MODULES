#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 5);
        Bureaucrat b2("Bob", 100);
        Form f1("Top Secret Form", 10, 50);
        Form f2("Basic Form", 120, 130);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        b1.signForm(f1);  
        b2.signForm(f1);  

        std::cout << f1 << std::endl; 
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat boss("Big Boss", 1);
        Bureaucrat employee("Low Level", 140);
        Bureaucrat intern("Intern", 150);

        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm roboForm("patient");
        PresidentialPardonForm pardonForm("criminal");

        std::cout << "\n--- Signing Forms ---" << std::endl;
        boss.signAForm(shrubForm);
        boss.signAForm(roboForm);
        boss.signAForm(pardonForm);

        std::cout << "\n--- Trying to Sign with Low-Level Bureaucrat ---" << std::endl;
        employee.signAForm(shrubForm);  
        intern.signAForm(roboForm);    

        std::cout << "\n--- Executing Forms ---" << std::endl;
        boss.executeForm(shrubForm);   
        boss.executeForm(roboForm);    
        boss.executeForm(pardonForm); 

        std::cout << "\n--- Trying to Execute with Low-Level Bureaucrat ---" << std::endl;
        employee.executeForm(roboForm); 

    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
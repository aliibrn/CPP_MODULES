#include "RobotomyRequestForm.hpp"  

RobotomyRequestForm::RobotomyRequestForm(): AForm("Default", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm(target, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy.getName(), copy.getgradeTosign(), copy.getgradeToexecute()){

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){
    if(this != &copy){
        AForm::operator=(copy);
    }
    return *this;
}

 RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "destructor of Robotmyrequestform" << std::endl;
 }

 void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (!getisigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getgradeToexecute())
        throw GradeTooLowException();

    std::cout << "* Drilling noises *" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << getName() << " has been successfully robotomized!" << std::endl;
    else
        std::cout << "Robotomy of " << getName() << " failed!" << std::endl;
}

AForm* RobotomyRequestForm::create(const std::string& target) { 
    return new RobotomyRequestForm(target); 
}
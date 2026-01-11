#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("default", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm(target, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy.getName(), copy.getgradeTosign(), copy.getgradeToexecute()){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
    if(this != &copy){
        AForm::operator=(copy);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "destructor of Presidentialpardonform" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!getisigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getgradeToexecute())
        throw GradeTooLowException();

    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm* PresidentialPardonForm::create(const std::string& target) { 
    return new PresidentialPardonForm(target); 
}
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm(target, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy.getName(), copy.getgradeTosign(), copy.getgradeToexecute()){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy){
    if(this != &copy){
        AForm::operator=(copy);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Destructor of ShrubberyCreationForm" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getisigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getgradeToexecute())
        throw GradeTooLowException();

    std::string filename = getName() + "_shrubbery";
    std::ofstream file(filename.c_str());  
    file << "      /\\      \n";
    file << "     /  \\     \n";
    file << "    /    \\    \n";
    file << "   /      \\   \n";
    file << "  /        \\  \n";
    file << " /__________\\ \n";
    file.close();
}

AForm* ShrubberyCreationForm::create(const std::string& target) { 
    return new ShrubberyCreationForm(target); 
}


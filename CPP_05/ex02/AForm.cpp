#include "AForm.hpp"

AForm::AForm(): name("DefaultAForm"), isigned(false), gradeTosign(150), gradeToexecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isigned(false),
      gradeTosign(gradeToSign),
      gradeToexecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& copy): name(copy.name), isigned(copy.isigned), gradeTosign(copy.gradeTosign), gradeToexecute(copy.gradeToexecute){

}

AForm& AForm::operator=(const AForm& copy){
    if(this != &copy){
        isigned = copy.isigned;
    }
    return *this;
}

AForm::~AForm(){
    std::cout << "Destructor of AForm: " << name << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade is too High!";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade is too Low!";
}

std::string AForm::getName() const{
    return name;
}

int AForm::getgradeTosign() const{
    return gradeTosign;
}

int AForm::getgradeToexecute() const{
    return gradeToexecute;
}

bool AForm::getisigned() const{ 
    return isigned; 
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << "AForm: " << AForm.getName()
       << ", Required grade to sign: " << AForm.getgradeTosign()
       << ", Required grade to execute: " << AForm.getgradeToexecute()
       << ", Signed: " << (AForm.getisigned() ? "Yes" : "No");
    return os;
}


void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeTosign)
        throw GradeTooLowException();
    isigned = true;
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm is not signed!";
}
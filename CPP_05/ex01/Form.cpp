#include "Form.hpp"

Form::Form(): name("DefaultForm"), isigned(false), gradeTosign(150), gradeToexecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isigned(false),
      gradeTosign(gradeToSign),
      gradeToexecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& copy): name(copy.name), isigned(copy.isigned), gradeTosign(copy.gradeTosign), gradeToexecute(copy.gradeToexecute){

}

Form& Form::operator=(const Form& copy){
    if(this != &copy){
        isigned = copy.isigned;
    }
    return *this;
}

Form::~Form(){
    std::cout << "Destructor of Form: " << name << std::endl;
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade is too High!";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade is too Low!";
}

std::string Form::getName() const{
    return name;
}

int Form::getgradeTosign() const{
    return gradeTosign;
}

int Form::getgradeToexecute() const{
    return gradeToexecute;
}

bool Form::getisigned() const{ 
    return isigned; 
}

std::ostream &operator<<(std::ostream &os, const Form &Form)
{
    os << "Form: " << Form.getName()
       << ", Required grade to sign: " << Form.getgradeTosign()
       << ", Required grade to execute: " << Form.getgradeToexecute()
       << ", Signed: " << (Form.getisigned() ? "Yes" : "No");
    return os;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeTosign)
        throw GradeTooLowException();
    isigned = true;
}
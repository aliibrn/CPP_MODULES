#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &_name, int _grade) : name(_name)
{
    if (_grade < 1)
    {
       throw GradeTooHighException();
    }
    if (_grade > 150)
    {
        throw GradeTooLowException();
    }
    grade = _grade;
}

Bureaucrat::Bureaucrat(): name("Default"), grade(150){}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name(copy.name), grade(copy.grade){}
 
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy){
    if(this != &copy){
        grade = copy.grade;
    }
    return *this;
}

const std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too High!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too Low!";
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor " << getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}

void Bureaucrat::signAForm(AForm& AForm) const {
    try {
        AForm.beSigned(*this);
        std::cout << name << " signed " << AForm.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << name << " couldn't sign " << AForm.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
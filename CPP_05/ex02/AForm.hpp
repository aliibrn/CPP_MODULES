#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool isigned;
    const int gradeTosign;
    const int gradeToexecute;

public:
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& copy);
    AForm& operator=(const AForm& copy);
    virtual ~AForm();

    std::string getName() const;
    int getgradeTosign() const;
    int getgradeToexecute() const;
    bool getisigned() const;

    void beSigned(const Bureaucrat &b);

    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &Form);

#endif
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool isigned;
    const int gradeTosign;
    const int gradeToexecute;

public:
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form& copy);
    Form& operator=(const Form& copy);
    ~Form();

    std::string getName() const;
    int getgradeTosign() const;
    int getgradeToexecute() const;
    bool getisigned() const;

    void beSigned(const Bureaucrat &b);

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
};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif
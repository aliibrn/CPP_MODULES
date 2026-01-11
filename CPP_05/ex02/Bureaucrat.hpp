#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class  Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        /*                     OCF                                          */
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();
            
        const std::string getName() const;
        int getGrade() const;
                
            void incrementGrade();
            void decrementGrade();

        void signAForm(AForm& Aform) const;

        void executeForm(AForm const &form) const;

        // exception class GradeTooHighException
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw(); // std::exception message , we need to overload it as the subject required
        };

        // exception class GradeTooLowException
        class GradeTooLowException : public std::exception { 
            public:
                const char* what() const throw(); // same
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
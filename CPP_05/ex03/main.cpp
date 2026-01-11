#include "Intern.hpp"

int main() {
    Intern intern;
    Bureaucrat boss("Boss", 1);

    AForm* form1 = intern.makeForm("robotomy request", "Bender");
    AForm* form2 = intern.makeForm("shrubbery creation", "Garden");
    AForm* form3 = intern.makeForm("presidential pardon", "Alice");
    AForm* form4 = intern.makeForm("unknown form", "Nobody");

    if (form1) {
        boss.signAForm(*form1);
        boss.executeForm(*form1);
        delete form1;
    }
    if (form2) {
        boss.signAForm(*form2);
        boss.executeForm(*form2);
        delete form2;
    }
    if (form3) {
        boss.signAForm(*form3);
        boss.executeForm(*form3);
        delete form3;
    }

    delete form4;
    return 0;
}
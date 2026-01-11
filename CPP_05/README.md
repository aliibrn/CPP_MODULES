# C++ Module 05: Exceptions

This module is about handling errors and other exceptional situations in C++ using exceptions. You will learn how to throw and catch exceptions, and how to design classes that are exception-safe.

## Concepts Covered

- **Exceptions:** A mechanism for handling runtime errors in a structured way.
- **`try`, `throw`, `catch`:** The keywords used for exception handling.
- **Stack Unwinding:** What happens when an exception is thrown and not caught in the current scope.
- **Exception Safety:** Writing code that behaves correctly even when exceptions are thrown.
- **Nested Exceptions:** How to handle exceptions within `catch` blocks.

## Exercises

### Exercise 00: Mommy, I'm a bureaucrat!

- **Files:** `ex00/Bureaucrat.cpp`, `ex00/main.cpp`
- **Purpose:** To introduce the basics of exception handling. You will create a `Bureaucrat` class with a grade that must be within a certain range. If an attempt is made to create a `Bureaucrat` with an invalid grade, an exception is thrown.

### Exercise 01: Form up, maggots!

- **Files:** `ex01/Bureaucrat.cpp`, `ex01/Form.cpp`, `ex01/main.cpp`
- **Purpose:** To apply exception handling to a more complex scenario. You will create a `Form` class that can be signed by a `Bureaucrat`. The `signForm()` method of the `Bureaucrat` will throw an exception if the bureaucrat's grade is not high enough to sign the form.

### Exercise 02: No, you need to do your paperwork!

- **Files:** `ex02/AForm.cpp`, `ex02/Bureaucrat.cpp`, `ex02/PresidentialPardonForm.cpp`, `ex02/RobotomyRequestForm.cpp`, `ex02/ShrubberyCreationForm.cpp`, `ex02/main.cpp`
- **Purpose:** This exercise introduces abstract base classes for forms. You will create an abstract `AForm` class and three concrete form classes that inherit from it. Each form has a different action that can be executed by a `Bureaucrat` with a sufficiently high grade.

### Exercise 03: At least this module is decent

- **Files:** `ex03/AForm.cpp`, `ex03/Bureaucrat.cpp`, `ex03/Intern.cpp`, `ex03/PresidentialPardonForm.cpp`, `ex03/RobotomyRequestForm.cpp`, `ex03/ShrubberyCreationForm.cpp`, `ex03/main.cpp`
- **Purpose:** To practice polymorphism and dynamic allocation in the context of exception handling. You will create an `Intern` class that can create different types of forms based on a string.

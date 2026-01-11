# C++ Module 03: Inheritance

This module explores the concept of inheritance, a fundamental pillar of object-oriented programming. You will learn how to create new classes that reuse, extend, and modify the behavior of existing classes.

## Concepts Covered

- **Inheritance:** Creating derived classes from a base class.
- **Access Specifiers:** `public`, `protected`, and `private` inheritance.
- **Function Overriding:** Redefining base class methods in a derived class.
- **The Diamond Problem:** A classic issue with multiple inheritance and how to solve it using virtual inheritance.

## Exercises

### Exercise 00: Aaaaand... OPEN!

- **Files:** `ex00/ClapTrap.cpp`, `ex00/main.cpp`
- **Purpose:** To create a base class `ClapTrap` that will be the foundation for other classes in this module. It has basic attributes like hit points, energy points, and attack damage.

### Exercise 01: Serena, my love!

- **Files:** `ex01/ScavTrap.cpp`, `ex01/main.cpp`
- **Purpose:** To create a `ScavTrap` class that inherits from `ClapTrap`. This exercise demonstrates how a derived class can have its own unique member functions and how its constructor and destructor are chained to the base class.

### Exercise 02: Repetitive work

- **Files:** `ex02/FragTrap.cpp`, `ex02/main.cpp`
- **Purpose:** Similar to the previous exercise, you will create a `FragTrap` class that also inherits from `ClapTrap`. This reinforces the concepts of inheritance and specialization.

### Exercise 03: Now it's weird...

- **Files:** `ex03/DiamondTrap.cpp`, `ex03/main.cpp`
- **Purpose:** This exercise tackles the "Diamond Problem." You will create a `DiamondTrap` class that inherits from both `FragTrap` and `ScavTrap`. You'll learn how to use virtual inheritance to resolve the ambiguity that arises from this multiple inheritance scenario.

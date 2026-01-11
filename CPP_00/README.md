# C++ Module 00: Introduction to C++

This first module is a gentle introduction to C++ and its core concepts, transitioning from C. It covers the fundamental differences and introduces the object-oriented paradigm.

## Concepts Covered

- **Namespaces:** Using `std::` to avoid name collisions.
- **Classes and Instances:** Defining classes with attributes and member functions.
- **Encapsulation:** Using `public` and `private` access specifiers to control access to class members.
- **The `this` Pointer:** Understanding how member functions access the object they are called on.
- **Stream I/O:** Using `iostream` for input and output, as an alternative to C's `stdio`.
- **Initialization Lists:** Properly initializing class members in constructors.
- **Static Members:** Understanding members that belong to the class rather than an instance.

## Exercises

### Exercise 00: Megaphone

- **Files:** `ex00/megaphone.cpp`
- **Purpose:** A simple program to practice basic C++ syntax and I/O. The program takes strings as arguments and prints them in uppercase.

### Exercise 01: My Awesome PhoneBook

- **Files:** `ex01/PhoneBook.cpp`, `ex01/Contact.cpp`, `ex01/main.cpp`
- **Purpose:** This exercise involves creating a simple phonebook. It's a practical application of classes, instances, and managing a collection of objects.
- **`Contact` class:** Represents a single contact with fields like first name, last name, nickname, etc.
- **`PhoneBook` class:** Manages an array of `Contact` objects and provides an interface to add new contacts and search for existing ones.

### Exercise 02: The Job Of Your Dreams

- **Files:** `ex02/Account.cpp`, `ex02/tests.cpp`
- **Purpose:** This exercise is about implementing a bank account class. The provided `tests.cpp` file helps verify the implementation. It focuses on correctly handling class state and behavior through member functions.

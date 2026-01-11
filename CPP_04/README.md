# C++ Module 04: Subtype Polymorphism, Abstract Classes, and Interfaces

This module covers subtype polymorphism, a powerful feature of C++ that allows you to treat objects of different classes in a uniform way. It also introduces abstract classes and interfaces.

## Concepts Covered

- **Polymorphism:** Using a base class pointer or reference to refer to objects of derived classes.
- **Virtual Functions:** Functions that can be overridden in derived classes and are resolved at runtime.
- **Abstract Classes:** Classes that cannot be instantiated and are meant to be used as base classes.
- **Pure Virtual Functions:** Virtual functions with no implementation, which force derived classes to provide their own.
- **Interfaces:** Abstract classes that have only pure virtual functions.
- **Deep vs. Shallow Copy:** Understanding the difference and when to implement a deep copy.

## Exercises

### Exercise 00: Polymorphism

- **Files:** `ex00/Animal.cpp`, `ex00/Cat.cpp`, `ex00/Dog.cpp`, `ex00/WrongAnimal.cpp`, `ex00/WrongCat.cpp`, `ex00/main.cpp`
- **Purpose:** To introduce the concept of polymorphism and virtual functions. You will create an `Animal` base class with derived `Cat` and `Dog` classes. The `makeSound()` function is made virtual to demonstrate polymorphic behavior. The `WrongAnimal` and `WrongCat` classes are used to show what happens when `virtual` is omitted.

### Exercise 01: I don't want to set the world on fire

- **Files:** `ex01/Animal.cpp`, `ex01/Cat.cpp`, `ex01/Dog.cpp`, `ex01/Brain.cpp`, `ex01/main.cpp`
- **Purpose:** This exercise focuses on the difference between shallow and deep copies. The `Cat` and `Dog` classes now have a `Brain` member, which is a dynamically allocated array of ideas. You must ensure that when a `Cat` or `Dog` is copied, its `Brain` is also copied (a deep copy).

### Exercise 02: Abstract class

- **Files:** `ex02/Animal.cpp`, `ex02/Cat.cpp`, `ex02/Dog.cpp`, `ex02/main.cpp`
- **Purpose:** To introduce abstract classes and pure virtual functions. The `Animal` class is made abstract by giving it a pure virtual `makeSound()` function. This means you can no longer create instances of `Animal`, and any class that inherits from `Animal` must implement `makeSound()`.

# C++ Module 08: Standard Template Library (STL)

This module provides an introduction to the C++ Standard Template Library (STL), a powerful collection of template classes and functions that provide common data structures and algorithms.

## Concepts Covered

- **STL Containers:** `vector`, `list`, `map`, `stack`, `queue`, etc.
- **STL Algorithms:** `find`, `sort`, `for_each`, `copy`, etc.
- **STL Iterators:** A generalization of pointers that allow you to traverse the elements of a container.

## Exercises

### Exercise 00: Easy find

- **Files:** `ex00/main.cpp`
- **Purpose:** To practice using STL containers and algorithms. You will write a function `easyfind` that takes a container and a value, and returns the first occurrence of the value in the container.

### Exercise 01: Span

- **Files:** `ex01/main.cpp`
- **Purpose:** This exercise involves creating a class `Span` that can store a large number of integers. You will then implement methods to find the shortest and longest spans between any two numbers in the `Span`. This exercise is designed to make you think about the efficiency of your algorithms.

### Exercise 02: Mutated abomination

- **Files:** `ex02/main.cpp`
- **Purpose:** To demonstrate how to extend an STL container by inheriting from it. You will create a `MutantStack` class that inherits from `std::stack` and adds iterator support.

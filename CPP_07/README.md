# C++ Module 07: C++ Templates

This module introduces C++ templates, a powerful feature for writing generic, reusable code. You will learn how to create function templates and class templates.

## Concepts Covered

- **Templates:** A mechanism for writing code that works with any data type.
- **Function Templates:** Generic functions that can operate on different data types.
- **Class Templates:** Generic classes that can be instantiated with different data types.
- **Template Instantiation:** The process by which the compiler generates a specific version of a template for a given data type.

## Exercises

### Exercise 00: A few functions

- **Files:** `ex00/main.cpp`
- **Purpose:** To introduce function templates. You will create generic versions of `swap`, `min`, and `max` that can work with any data type that supports the necessary operators.

### Exercise 01: Iter

- **Files:** `ex01/main.cpp`
- **Purpose:** To practice writing a more complex function template. You will create a function `iter` that takes an array, its length, and a function as arguments. The `iter` function applies the given function to each element of the array.

### Exercise 02: Test your templates

- **Files:** `ex02/main.cpp`
- **Purpose:** To introduce class templates. You will create a class template `Array` that can be used to create arrays of any data type. This exercise will also require you to handle memory management and operator overloading within a class template.

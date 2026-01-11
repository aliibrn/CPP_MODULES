# C++ Module 06: C++ Casts

This module focuses on the different types of casts available in C++ and when to use them. It emphasizes the importance of type safety and the dangers of using C-style casts.

## Concepts Covered

- **`static_cast`:** For conversions between related types (e.g., numeric types, pointers in an inheritance hierarchy).
- **`dynamic_cast`:** For safely downcasting pointers and references in an inheritance hierarchy. It performs a runtime check to ensure the conversion is valid.
- **`const_cast`:** For adding or removing `const` and `volatile` qualifiers.
- **`reinterpret_cast`:** For low-level, unsafe conversions between unrelated types. Its use is highly discouraged.
- **Serialization:** The process of converting an object into a stream of bytes to store or transmit it.

## Exercises

### Exercise 00: Scalar conversion

- **Files:** `ex00/main.cpp`
- **Purpose:** To practice using `static_cast` for converting between scalar types (e.g., `int`, `float`, `double`, `char`). The program takes a string representation of a number and converts it to different numeric types.

### Exercise 01: Serialization

- **Files:** `ex01/main.cpp`
- **Purpose:** This exercise demonstrates the use of `reinterpret_cast` for serialization and deserialization. You will write functions to serialize a data structure to a raw byte stream and then deserialize it back. This exercise highlights the power and danger of `reinterpret_cast`.

### Exercise 02: Type identification

- **Files:** `ex02/main.cpp`
- **Purpose:** To practice using `dynamic_cast` for runtime type identification. You will create a hierarchy of classes and write a function that can identify the actual type of an object at runtime using `dynamic_cast`.

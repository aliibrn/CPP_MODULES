# C++ Module 01: Memory, Pointers, and References

This module dives into memory management in C++, covering allocation, deallocation, pointers, and references. It highlights the differences from C and introduces C++-specific ways of handling memory.

## Concepts Covered

- **Memory Allocation:** Using `new` and `delete` for dynamic memory management.
- **Pointers:** A refresher on pointers and their use with dynamically allocated memory.
- **References:** Understanding what references are and how they differ from pointers.
- **File I/O:** Introduction to file streams (`fstream`) for reading from and writing to files.
- **Pointers to Member Functions:** A more advanced concept for calling member functions indirectly.

## Exercises

### Exercise 00: BraiiiiiiinnnzzzZ

- **Files:** `ex00/Zombie.cpp`, `ex00/newZombie.cpp`, `ex00/randomChump.cpp`, `ex00/main.cpp`
- **Purpose:** Introduces dynamic allocation with `new` and deallocation with `delete`. You create a `Zombie` class and learn to manage its lifecycle.

### Exercise 01: Moar brainz!

- **Files:** `ex01/Zombie.cpp`, `ex01/ZombieHorde.cpp`, `ex01/main.cpp`
- **Purpose:** Expands on the previous exercise by allocating an array of objects. This exercise teaches how to handle arrays of dynamically allocated objects.

### Exercise 02: HI THIS IS BRAIN

- **Files:** `ex02/main.cpp`
- **Purpose:** This exercise focuses on the concept of references in C++. It demonstrates how references can be used as aliases for other variables.

### Exercise 03: Unnecessary violence

- **Files:** `ex03/HumanA.cpp`, `ex03/HumanB.cpp`, `ex03/Weapon.cpp`, `ex03/main.cpp`
- **Purpose:** To illustrate the difference between pointers and references in a practical scenario. `HumanA` takes a `Weapon` by reference in its constructor, while `HumanB` takes a pointer.

### Exercise 04: Sed is for losers

- **Files:** `ex04/main.cpp`
- **Purpose:** A practical exercise in string manipulation and file I/O. The program reads from a file, replaces all occurrences of a string, and writes the result to a new file.

### Exercise 05: Harl 2.0

- **Files:** `ex05/Harl.cpp`, `ex05/main.cpp`
- **Purpose:** Introduces pointers to member functions. The `Harl` class has member functions for different complaint levels, and you call them using pointers.

### Exercise 06: Harl filter

- **Files:** `ex06/Harl.cpp`, `ex06/main.cpp`
- **Purpose:** Builds on the previous exercise to create a filtering system for Harl's complaints, demonstrating a more practical use of pointers to member functions.

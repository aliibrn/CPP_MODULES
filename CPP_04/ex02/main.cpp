#include "Classes.hpp"

void testDeepCopy() {
    std::cout << CYAN << "=== Deep Copy Test ===" << RESET << std::endl;
    Dog dog1;
    dog1.makeSound();
    Dog dog2 = dog1; 
    dog2.makeSound();
    Dog dog3;
    dog3 = dog1; 
    dog3.makeSound();
    std::cout << CYAN << "=== End Deep Copy Test ===" << RESET << std::endl;
}

int main() {
    std::cout << CYAN << "=== Polymorphism Test ===" << RESET << std::endl;
    
    const int size = 6;
    AAnimal* animals[size];

    for (int i = 0; i < size / 2; ++i) {
        animals[i] = new Dog();
        animals[i + size / 2] = new Cat();
    }

    for (int i = 0; i < size; ++i) {
        animals[i]->makeSound(); 
    }

    for (int i = 0; i < size; ++i) {
        delete animals[i]; 
    }
    std::cout << CYAN << "=== End Polymorphism Test ===" << RESET << std::endl;
    testDeepCopy();
    // AAnimal animal;
    
    return 0;
}
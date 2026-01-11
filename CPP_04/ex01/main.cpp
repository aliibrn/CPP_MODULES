#include "Classes.hpp"

int main()
{

    const int size = 6;
    Animal* animals[size];

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
    return 0;
}
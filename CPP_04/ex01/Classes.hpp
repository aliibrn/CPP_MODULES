#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <string>

#define RESET   "\033[0m"

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal& copy);
    Animal& operator=(const Animal& copy);
    virtual ~Animal(); 
    
    std::string getType() const;
    virtual void makeSound() const; 
};

class Brain{
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& copy);
        Brain& operator=(const Brain& copy);
        ~Brain();
};

class Dog : public Animal {
private:
    Brain *brain; 

public:
    Dog();
    Dog(const Dog& copy);
    Dog& operator=(const Dog& copy);
    ~Dog();
    void makeSound() const ;
};

class Cat : public Animal {
private:
    Brain *brain; 

public:
    Cat();
    Cat(const Cat& copy);
    Cat& operator=(const Cat& copy);
    ~Cat();
    void makeSound() const ;
};

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& copy);
    WrongAnimal& operator=(const WrongAnimal& copy);
    virtual ~WrongAnimal();
    
    std::string getType() const;
    void makeSound() const; 
};

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat& copy);
    WrongCat& operator=(const WrongCat& copy);
    ~WrongCat();
    void makeSound() const;
};


#endif
#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h> 
#include <iostream>
#include <string>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

struct Data {
    std::string name;
};


class Serializer {
    private:
        Serializer();
        ~Serializer();
        Serializer& operator=(const Serializer& copy);
        Serializer(const Serializer& copy);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
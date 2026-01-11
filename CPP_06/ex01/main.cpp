#include "Serialization.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <value>" << std::endl;
        return 1;
    }
    
    Data original;
    original.name = av[1];

    std::cout << "Original Data pointer: " << &original << std::endl;
    
    uintptr_t raw = Serializer::serialize(&original);
    std::cout << YELLOW <<  "Serialized as uintptr_t: " << COLOR_RESET << raw << std::endl;

    Data* result = Serializer::deserialize(raw);
    std::cout << YELLOW << "Deserialized pointer: " << COLOR_RESET << result << std::endl;

    if (result == &original)
        std::cout << GREEN << "Deserialized pointer matches the original!" << COLOR_RESET << std::endl;
    else
        std::cout << RED << "Mismatch!" << COLOR_RESET << std::endl;

    std::cout << "Name: " << result->name << std::endl;

    return 0;
}

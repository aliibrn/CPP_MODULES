#include "easyfind.hpp"

template <typename T>
void    easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
    {
        std::cout << "Value " << value << " found in the container." << std::endl;
    }
    else
    {
        throw std::runtime_error("Value not found in the container.");
    }
}
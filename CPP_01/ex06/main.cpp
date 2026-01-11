#include "Harl.hpp"

int main(int ac, char **av)
{
    if(ac != 2 )
    {
        std::cerr << "NO ARGUMENTS" << std::endl;
        return 2;
    }
    Harl test;

    test.complain(av[1]);
}
#include "Zombie.hpp"

int main()
{
    Zombie *test = newZombie("Foo");
    test->announce();
    randomChump("hamouda");
    delete test;
}
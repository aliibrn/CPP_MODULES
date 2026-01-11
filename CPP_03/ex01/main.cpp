#include "ScavTrap.hpp"

int main()
{   
    ScavTrap *t2 = new ScavTrap("test");
    t2->attack("gamouda");
    delete t2;

}
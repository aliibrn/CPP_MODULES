#include <iostream>

void     everybody_is_awake(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        std::cout << str[i];
        i++;
    }
}

int main(int ac, char **av)
{
    int i = 1;

    if(ac > 1)
    {
        while(av[i])
        {
            everybody_is_awake(av[i]);
            i++;
        }
        std::cout << "\n";
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
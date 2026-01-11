#pragma once

#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T *array, int length, F func)
{
    if (!array || length <= 0)
        return;
    for (int i = 0; i < length; ++i)
    {
        func(array[i]);
    }
}

template <typename T>
void print(const T &x)
{
    std::cout << x << std::endl;
}
#pragma once

#include <iostream>
#include <vector>
#include <limits.h>
#include <iterator>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
    unsigned int N;
    std::vector<int> numbers;

public:
    Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    template <typename T>
    void addNumbers(T begin, T end)
    {
        for (T it = begin; it != end; ++it)
        {
            addNumber(*it);
        }
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
};

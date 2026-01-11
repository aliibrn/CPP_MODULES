#include "Span.hpp"

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span& other) : N(other.N), numbers(other.numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= N) {
        throw std::length_error("Span is full");
    }
    numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int>::const_iterator minIt = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(numbers.begin(), numbers.end());
    return *maxIt - *minIt;
}
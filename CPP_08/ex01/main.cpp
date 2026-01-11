#include "Span.hpp"

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }

int main() {
    try {
        Span span(5);
        span.addNumber(1);
        span.addNumber(3);
        span.addNumber(7);
        span.addNumber(9);
        span.addNumber(2);

        std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << span.longestSpan() << std::endl;

        // Uncommenting the next line will throw an exception
        // span.addNumber(10); // throw a length_error

        std::cout << "----------------SECOND TESTING------------------" << std::endl;
        Span span2(10);
        std::vector<int> moreNumbers;
        moreNumbers.push_back(5);
        moreNumbers.push_back(15);
        moreNumbers.push_back(25);
        moreNumbers.push_back(35);
        moreNumbers.push_back(45);
        moreNumbers.push_back(55);
        moreNumbers.push_back(65);
        moreNumbers.push_back(75);
        moreNumbers.push_back(85);
        moreNumbers.push_back(95);
        span2.addNumbers(moreNumbers.begin(), moreNumbers.end());
        std::cout << "Shortest Span: " << span2.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << span2.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
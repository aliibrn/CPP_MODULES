#include "iter.hpp"

int main() {
    int arrInt[] = {1, 2, 3, 4, 5};
    std::string arrStr[] = {"hello", "world", "from", "iter"};

    std::cout << "------- Print int array:" << std::endl;
    iter(arrInt, 5, print<int>);

    std::cout << "\n------- Print string array:" << std::endl;
    iter(arrStr, 4, print<std::string>);
}

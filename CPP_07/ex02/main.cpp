#include "Array.hpp"

int main() {
    try {
        std::cout << "Creating empty array...\n";
        Array<int> empty;
        std::cout << "Size = " << empty.size() << "\n";

        std::cout << "\nCreating array of 5 integers...\n";
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); ++i)
            arr[i] = i * 2;

        std::cout << "Array contents:\n";
        for (unsigned int i = 0; i < arr.size(); ++i)
            std::cout << "arr[" << i << "] = " << arr[i] << "\n";

        std::cout << "\nTesting deep copy...\n";
        Array<int> copy = arr;
        arr[0] = 999;
        std::cout << "arr[0] = " << arr[0] << "\n";
        std::cout << "copy[0] = " << copy[0] << "\n";  

        std::cout << "\nTesting out-of-bounds...\n";
        std::cout << arr[10] << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

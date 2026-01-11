#include "PmergeMe.hpp"

int main(int ac, char **av) {
    PmergeMe sorter;
    
    if (!sorter.parseArguments(ac, av)) {
        return 1;
    }
    
    sorter.sort();
}
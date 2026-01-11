#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>

class PmergeMe {
private:
    std::deque<int> _deque;
    std::list<int> _list;
    
    void mergeInsertSortDeque(std::deque<int>& container);
    void insertionSortDeque(std::deque<int>& container, int left, int right);
    int binarySearchDeque(const std::deque<int>& container, int target, int left, int right);
    
    void mergeInsertSortList(std::list<int>& container);
    void insertionSortList(std::list<int>& container);
    std::list<int>::iterator binarySearchList(std::list<int>& container, int target);

    double getTime();
    bool isValidNumber(const std::string& str);
    void printContainer(const std::deque<int>& container, const std::string& prefix);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& copy);
    PmergeMe& operator=(const PmergeMe& copy);
    ~PmergeMe();
    
    bool parseArguments(int argc, char** argv);
    void sort();
};
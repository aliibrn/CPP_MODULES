#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy)
    : _deque(copy._deque), _list(copy._list) {

}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy) {
    if (this != &copy) {
        _deque = copy._deque;
        _list = copy._list;
    }
    return *this;
}


double PmergeMe::getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

bool PmergeMe::isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it)) return false;
    }
    
    std::stringstream ss(str);
    long num;
    ss >> num;
    
    return num > 0 && num <= 2147483647;
}

bool PmergeMe::parseArguments(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error: No arguments provided" << std::endl;
        return false;
    }
    
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        
        if (!isValidNumber(arg)) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        int num = std::atoi(arg.c_str());
        _deque.push_back(num);
        _list.push_back(num);
    }
    
    if (_deque.size() > 3000) {
        std::cerr << "Error: Too many elements (max 3000)" << std::endl;
        return false;
    }
    
    return true;
}

void PmergeMe::printContainer(const std::deque<int>& container, const std::string& prefix) {
    std::cout << prefix;
    for (std::deque<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it;
        if (it + 1 != container.end()) std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& container) {
    if (container.size() <= 1) return;
    
    if (container.size() <= 5) {
        insertionSortDeque(container, 0, container.size() - 1);
        return;
    }
    
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> unpaired;
    
    for (size_t i = 0; i < container.size(); i += 2) {
        if (i + 1 < container.size()) {
            int a = container[i];
            int b = container[i + 1];
            if (a <= b) {
                pairs.push_back(std::make_pair(a, b));
            } else {
                pairs.push_back(std::make_pair(b, a));
            }
        } else {
            unpaired.push_back(container[i]);
        }
    }
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = i + 1; j < pairs.size(); ++j) {
            if (pairs[i].second > pairs[j].second) {
                std::swap(pairs[i], pairs[j]);
            }
        }
    }
    
    std::deque<int> mainChain;
    std::deque<int> toInsert;
    
    if (!pairs.empty()) {
        mainChain.push_back(pairs[0].first);
        mainChain.push_back(pairs[0].second);
        
        for (size_t i = 1; i < pairs.size(); ++i) {
            mainChain.push_back(pairs[i].second);
            toInsert.push_back(pairs[i].first);
        }
    }
    
    for (size_t i = 0; i < toInsert.size(); ++i) {
        int pos = binarySearchDeque(mainChain, toInsert[i], 0, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, toInsert[i]);
    }
    
    for (size_t i = 0; i < unpaired.size(); ++i) {
        int pos = binarySearchDeque(mainChain, unpaired[i], 0, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, unpaired[i]);
    }
    
    container = mainChain;
}

void PmergeMe::insertionSortDeque(std::deque<int>& container, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = container[i];
        int j = i - 1;
        
        while (j >= left && container[j] > key) { 
            container[j + 1] = container[j];
            --j;
        }
        container[j + 1] = key;
    }
}

int PmergeMe::binarySearchDeque(const std::deque<int>& container, int target, int left, int right) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (container[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

void PmergeMe::mergeInsertSortList(std::list<int>& container) {
    if (container.size() <= 1) return;
    
    if (container.size() <= 5) {
        insertionSortList(container);
        return;
    }
    std::list<std::pair<int, int> > pairs;
    std::list<int> unpaired;
    
    std::list<int>::iterator it = container.begin();
    while (it != container.end()) {
        int first = *it;
        ++it;
        if (it != container.end()) {
            int second = *it;
            ++it;
            if (first <= second) {
                pairs.push_back(std::make_pair(first, second));
            } else {
                pairs.push_back(std::make_pair(second, first));
            }
        } else {
            unpaired.push_back(first);
        }
    }
    
    if (pairs.size() > 1) {
        bool swapped;
        do {
            swapped = false;
            std::list<std::pair<int, int> >::iterator it1 = pairs.begin();
            std::list<std::pair<int, int> >::iterator it2 = it1;
            ++it2;
            
            while (it2 != pairs.end()) {
                if (it1->second > it2->second) {
                    std::swap(*it1, *it2);
                    swapped = true;
                }
                ++it1;
                ++it2;
            }
        } while (swapped);
    }
    
    std::list<int> mainChain;
    std::list<int> toInsert;
    
    if (!pairs.empty()) {
        std::list<std::pair<int, int> >::iterator pairIt = pairs.begin();
        mainChain.push_back(pairIt->first);
        mainChain.push_back(pairIt->second);
        ++pairIt;
        
        while (pairIt != pairs.end()) {
            mainChain.push_back(pairIt->second);
            toInsert.push_back(pairIt->first);
            ++pairIt;
        }
    }
    
    for (std::list<int>::iterator insertIt = toInsert.begin(); insertIt != toInsert.end(); ++insertIt) {
        std::list<int>::iterator pos = binarySearchList(mainChain, *insertIt);
        mainChain.insert(pos, *insertIt);
    }
    
    for (std::list<int>::iterator unpairedIt = unpaired.begin(); unpairedIt != unpaired.end(); ++unpairedIt) {
        std::list<int>::iterator pos = binarySearchList(mainChain, *unpairedIt);
        mainChain.insert(pos, *unpairedIt);
    }
    
    container = mainChain;
}

void PmergeMe::insertionSortList(std::list<int>& container) {
    if (container.size() <= 1) return;
    
    std::list<int>::iterator current = container.begin();
    ++current;
    
    while (current != container.end()) {
        int value = *current;
        std::list<int>::iterator pos = container.begin();
        
        while (pos != current && *pos <= value) {
            ++pos;
        }
        
        if (pos != current) {
            std::list<int>::iterator toErase = current;
            ++current;
            container.erase(toErase);
            container.insert(pos, value);
        } else {
            ++current;
        }
    }
}

std::list<int>::iterator PmergeMe::binarySearchList(std::list<int>& container, int target) {
    std::list<int>::iterator it = container.begin();
    
    while (it != container.end() && *it < target) {
        ++it;
    }
    
    return it;
}

void PmergeMe::sort() {
    double startTime, endTime;
    
    printContainer(_deque, "Before: ");
    
    std::deque<int> dequeCopy = _deque;
    startTime = getTime();
    mergeInsertSortDeque(dequeCopy);
    endTime = getTime();
    double dequeTime = endTime - startTime;
    
    printContainer(dequeCopy, "After:  ");
    
    std::list<int> listCopy = _list;
    startTime = getTime();
    mergeInsertSortList(listCopy);
    endTime = getTime();
    double listTime = endTime - startTime;
    
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque : " << dequeTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _list.size() 
              << " elements with std::list  : " << listTime << " us" << std::endl;
}
#include "easyfind.hpp"

int main(){
    std::vector<int> T1;
    T1.push_back(1);
    T1.push_back(2);
    T1.push_back(3);
    T1.push_back(10);
    T1.push_back(5);
    try{
        easyfind(T1, 10);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
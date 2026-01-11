#include "RPN.hpp"

int main(int ac, char **av){
    try{
        if(ac != 2){
            std::cerr << "Error: no arguments" << std::endl;
            throw 1;
        }
        RPN rpn;
        rpn.parse_numbers(av[1]);
        rpn.RPN_CALCULATIONS();
    }
    catch(int error){
        return 1;
    }
    catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }

}
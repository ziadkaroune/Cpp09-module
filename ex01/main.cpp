#include "RPN.hpp"


int main(int ac, char* av[]) {
    if (ac != 2) {
        std::cerr << "Error Arguments\"\n";
        return 1;
    }
    else
         RPN(av[1]) ;
}

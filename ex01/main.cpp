#include "RPN.hpp"


int main(int ac, char* av[]) {
    if (ac != 2) {
        std::cerr << "Error Arguments\n";
        return -1;
    }
    else
    {
        try{
             RPN(av[1]) ;
        }
        catch(std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
        return 0;   
}

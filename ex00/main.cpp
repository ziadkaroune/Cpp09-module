
#include "BitcoinExchange.hpp"

int main(int ac , char *av[])
{
    if(ac != 2)
    {
        std::cerr << "error argument | ./btc 'filename.txt' " << std::endl;   
        return 0;
    }
    try{
        bitcoin_exchange(av[1], store_data());
    }
    catch(std::exception &e)
    {
        std::cout << std::endl;
        std::cerr << "Error " << e.what() << std::endl;
    }
    
    
    
    return 0;
}
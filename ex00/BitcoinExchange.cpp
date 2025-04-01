#include "BitcoinExchange.hpp"

std::map<std::string , double>   store_data(void)   /// store data from csv file
{
    std::ifstream inputfile("data.csv");
    std::string  line;
    std::map<std::string , double> stock;

    if(!inputfile)  //file doesn't exist
        std::cerr << "insert database .csv file" << std::endl;
    std::getline(inputfile , line); // skip first line
    while(std::getline(inputfile , line) )
    {
        std::istringstream iss(line);
        std::string date;
        std::string price;

        if(std::getline(iss , date ,  ',') && std::getline(iss , price))
            stock[date] = stod(price) ;  
    }
    inputfile.close();
    return stock;
}

void bitcoin_exchange(char *filename ,  std::map<std::string , double> data )
{
    std::ifstream rateExchange(filename);
    if(!rateExchange) //file doesn't exist
        std::cerr << "error input file" << std::endl;

    std::string read;               // to extract date + rate
    std::string dateData;           // date 
    std::string toconvert;          // rate
    std::getline(rateExchange , read);
   while(std::getline(rateExchange , read))
   {

                    std::istringstream line(read);
                    if(std::getline(line ,  dateData , '|') && getline(line , toconvert))
                    {
                   
                        std::istringstream y(dateData);
                        dateData.erase(0, dateData.find_first_not_of(" \t"));
                        dateData.erase(dateData.find_last_not_of(" \t") + 1);

                        std::string year;
                        std::string month;
                        std::string day;
                               
                                while(std::getline(y , year , '-') && std::getline(y , month , '-') &&  std::getline(y , day)){

                                }
                        int Ye , M , D;
                        Ye = std::stoi(year);
                        M = std::stoi(month);
                        D = std::stoi(day);
                         if (Ye > 2022 || Ye < 2008 || M > 12 || D > 31 )
                                std::cout << "Error: bad input => " << dateData << std::endl;

                        else if (data.find(dateData) != data.end()) {
                                    if(stod(toconvert) < 0)  // negative value case
                                        std::cout << "Error: not a positive number." << std::endl;
                                    else if(stod(toconvert) > INT_MAX)  // big value case
                                        std::cout << "Error: too large a number." << std::endl;
                                    else
                                        std::cout <<  dateData << " => " << toconvert << " = " << data[dateData] * std::stod(toconvert) << std::endl;
                        } 
                        else {
                            std::map<std::string, double>::iterator it = data.lower_bound(dateData); // Get the lower bound for the key
                            if (it != data.begin()) { 
                                --it;  // Move iterator to the previous element
                                std::cout << dateData << " => " << toconvert << " = " << it->second * std::stod(toconvert) << std::endl;
                            }
                    }
                }
                    else{
                        std::cout << "Error: bad inputd => " << dateData << std::endl; 
                    }
   }
   
     rateExchange.close();
   
}
#ifndef BITCOIEXCHANGE_HPP
# define BITCOIEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream> 


std::map<std::string , double>   store_data(void) ;
void bitcoin_exchange(char *filename ,  std::map<std::string , double> data );

#endif
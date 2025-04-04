#ifndef  PmergeMe_HPP
#   define PmergeMe_HPP
#include <iostream>
#include <list>
#include <vector>
#include <stdexcept>
#include <string>
#include <ctime>  
#include <cstdlib>   

// parsing + store data to containers
std::list<int> unsorted_list(char **arg, int ac);
std::vector<int> unsorted_vector(char **arg, int ac);

// insertion algo
void insertionSortList(std::list<int>& arr );
void insertionSortVector(std::vector<int>& arr);

// merge algo
std::list<int> mergeList(std::list<int> left, std::list<int> right);
std::vector<int> mergeVect(const std::vector<int>& left, const std::vector<int>& right);

// main algo (combination insertion + algo)
std::list<int> mergeInsertionSort(std::list<int> arr);
std::vector<int> mergeInsertionSort(std::vector<int>& arr);

// print containers content
void printlist(std::list<int>& list, const std::string& status);
void printVector(std::vector<int>& vec, const std::string& status) ;

#endif
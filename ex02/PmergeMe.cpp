
#include "PmergeMe.hpp"

void insertionSortList(std::list<int>& arr ) {
    if (arr.size() < 2)
        return;
    
    std::list<int>::iterator it = arr.begin();
    ++it;  

    while (it != arr.end()) {
        std::list<int>::iterator current = it;
        std::list<int>::iterator prev = std::prev(it);
        ++it;

        while (current != arr.begin() && *current < *prev) {
            std::iter_swap(current, prev);
            current = prev;
            if (current != arr.begin())
                prev = std::prev(current);
        }
    }
}

void insertionSortVector(std::vector<int>& arr) {
    if (arr.size() < 2)
        return;

    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

std::list<int> mergeList(std::list<int> left, std::list<int> right) {
    std::list<int> merged;

    std::list<int>::iterator itLeft = left.begin();
    std::list<int>::iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end()) {
        if (*itLeft < *itRight) {
            merged.push_back(*itLeft);
            ++itLeft;
        } else {
            merged.push_back(*itRight);
            ++itRight;
        }
    }
    while (itLeft != left.end()) {
        merged.push_back(*itLeft);
        ++itLeft;
    }

    while (itRight != right.end()) {
        merged.push_back(*itRight);
        ++itRight;
    }

    return merged;
}

std::vector<int> mergeVect(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> merged;
    size_t i = 0, j = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i++]);
        } else {
            merged.push_back(right[j++]);
        }
    }

    while (i < left.size()) 
        merged.push_back(left[i++]);
    while (j < right.size()) 
        merged.push_back(right[j++]);

    return merged;
}

std::list<int> mergeInsertionSort(std::list<int> arr) {
    if (arr.size() <= 3) {
        insertionSortList(arr);  
        return arr;
    }

    std::list<int>::iterator midIt = arr.begin();
    std::advance(midIt, arr.size() / 2);   

    std::list<int> left(arr.begin(), midIt);
    std::list<int> right(midIt, arr.end());

    left = mergeInsertionSort(left);
    right = mergeInsertionSort(right);

    return mergeList(left, right);   
}

std::vector<int> mergeInsertionSort(std::vector<int>& arr) {
    if (arr.size() <= 3) {
        insertionSortVector(arr);
        return arr;
    }
    size_t mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    left = mergeInsertionSort(left);
    right = mergeInsertionSort(right);
    return mergeVect(left, right);
}

std::list<int> unsorted_list(char **arg, int ac) {
    std::list<int> list;
 
    for (int i = 1; i < ac; i++) {
        for (int y = 0; arg[i][y]; y++) {
            if (!isdigit(arg[i][y]))
                throw std::runtime_error("Error");
        }
        list.push_back(std::atoi(arg[i]));  
    }
    return list;
}

std::vector<int> unsorted_vector(char **arg, int ac) {
    std::vector<int> vec;

    for (int i = 1; i < ac; i++) {
        for (int y = 0; arg[i][y]; y++) {
            if (!isdigit(arg[i][y])) 
                throw std::runtime_error("Error: Non-numeric character detected.");
        }
        vec.push_back(std::atoi(arg[i]));  
    }

    return vec;
}

 void printlist(std::list<int>& list, const std::string& status) {
    std::list<int>::iterator it;
    if (status.compare("unsorted") == 0)
        std::cout << "Before : ";
    else
        std::cout << "After : ";

    for (it = list.begin(); it != list.end(); it++)
        std::cout << *it << " ";
    
    std::cout << std::endl;
}

 void printVector(std::vector<int>& vec, const std::string& status) {
    std::cout << status << " : ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

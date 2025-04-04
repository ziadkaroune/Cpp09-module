#include "PmergeMe.hpp"

static void expliciteTimealgo(int listSize, const std::string& cont_type, double time) {
    std::cout << "Time to process a range of " << listSize << " elements with std::" << cont_type << " : " << time << " us" << std::endl;
}
int main(int ac, char **av) {
    try {
        // Process list
        std::list<int> list = unsorted_list(av, ac);
        
        printlist(list, "unsorted");

   
        clock_t start = clock();
        list = mergeInsertionSort(list);
        clock_t end = clock();

        printlist(list, "After");
        
        double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;   
        expliciteTimealgo(list.size(), "list", duration);
        
 
        std::vector<int> vect = unsorted_vector(av , ac);
        start = clock();
        vect = mergeInsertionSort(vect);
        end = clock();
        duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;  
        expliciteTimealgo(vect.size(), "vector", duration);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

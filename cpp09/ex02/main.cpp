#include "PmergeMe.hpp"
#include <ctime>
#include <sstream>
#include <stdexcept>

std::vector<int>buildVector(char *arr[])
{
    std::vector<int> vec;
    for (int i = 0; arr[i]; i++)
    {
        std::istringstream iss(arr[i]);
        long num;
        std::string remains;
        if(!(iss >> num))
            throw std::runtime_error("Error");
        if(iss >> remains)
            throw std::runtime_error("Error");
        if (num < 0 || num > INT_MAX)
            throw std::runtime_error("Error");
        vec.push_back(num);
    }
    return vec;
}
std::deque<int> buildDeque(char *arr[])
{
    std::deque<int> deq;
    for (int i = 0; arr[i]; i++)
    {
        std::istringstream iss(arr[i]);
        long num;
        std::string remains;
        if(!(iss >> num))
            throw std::runtime_error("Error");
        if(iss >> remains)
            throw std::runtime_error("Error");
        if (num < 0 || num > INT_MAX)
            throw std::runtime_error("Error");
        deq.push_back(num);
    }
    return deq;
}

int main(int ac, char *av[])
{
    if (ac < 2)
    {
        std::cerr << "Error: program rquire a list of numbers as arguments";
        return 1;
    }
    try {
        PmergeMe con;
        std::vector<int> vec = buildVector(av + 1);
        std::deque<int> deq = buildDeque(av + 1);
    
        clock_t start_deq = clock();
        con.fordJohnsonDeque(deq);
        clock_t end_deq = clock();
    
        clock_t start_vect = clock();
        std::vector<int> res = con.fordJohnsonVector(vec);
        clock_t end_vect = clock();
    
        con.print_container(res , av + 1);
        double time_vect = (double)(end_vect - start_vect);
        double time_deq = (double)(end_deq - start_deq);
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector: " << time_vect << " us"<< std::endl;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque :" << time_deq << " us" << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    try {
        std::vector<int>::iterator it = easyfind(v, 5);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 99);
        std::cout << "Found in vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_back(50);
    try {
        std::list<int>::iterator it = easyfind(l, 30);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        std::list<int>::iterator it = easyfind(l, 99);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::deque<int> d;
    d.push_back(100);
    d.push_back(200);
    d.push_back(300);
    d.push_back(400);
    d.push_back(500);
    try {
        std::deque<int>::iterator it = easyfind(d, 300);
        std::cout << "Found in deque: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try {
        std::deque<int>::iterator it = easyfind(d, 99);
        std::cout << "Found in deque: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
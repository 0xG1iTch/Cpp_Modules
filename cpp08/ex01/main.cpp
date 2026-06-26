#include "span.hpp"
#include <cstdlib>

int main()
{
    Span sp(5);
    sp.addNumber(2147483647);
    sp.addNumber(-2147483648);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: "  << sp.longestSpan()  << std::endl;

    try {
        sp.addNumber(99);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    Span bigSp(10000);
    std::vector<int> vec;
    srand(42);
    for (int i = 0; i < 10000; i++)
        vec.push_back(rand());
    bigSp.addNumbers(vec.begin(), vec.end());
    std::cout << "Shortest span: " << bigSp.shortestSpan() << std::endl;
    std::cout << "Longest span: "  << bigSp.longestSpan()  << std::endl;

    return 0;
}
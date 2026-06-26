#include "MutantStack.hpp"

int main()
{
    MutantStack<int> ms;
    ms.push(11);
    ms.push(22);
    ms.push(33);
    std::cout << ms.top() << std::endl;

    ms.pop();
    std::cout << ms.size() << std::endl;

    ms.push(44);
    ms.push(55);
    ms.push(66);
    MutantStack<int>::iterator it = ms.begin();
    MutantStack<int>::iterator ite = ms.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(ms);
    return 0;
}
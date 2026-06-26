#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int r = std::rand() % 3;
    switch (r)
    {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return 0;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type of Object: " << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type of Object: " << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type of Object: " << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type of Object: " << "A" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type of Object: " << "B" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type of Object: " << "C" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}
}

int main()
{
    std::srand(std::time(0));
    for (int i = 0; i < 5; ++i)
    {
        Base* ptr = generate();
        std::cout << "---identify by Pointer---" << std::endl;
        identify(ptr);
        std::cout << "---identify by Reference---" << std::endl;
        identify(*ptr);
        delete ptr;
    }
}
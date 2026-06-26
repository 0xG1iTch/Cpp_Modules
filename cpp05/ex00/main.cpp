#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Valid bureaucrat ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Grade too high ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 0);
        std::cout << bob << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n=== Grade too low ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 151);
        std::cout << bob << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n=== Increment at boundary ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 1);
        std::cout << bob << std::endl;
        bob.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n=== Decrement at boundary ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 150);
        std::cout << bob << std::endl;
        bob.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << "\n=== Valid increment ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 2);
        bob.incrementGrade();
        std::cout << bob << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
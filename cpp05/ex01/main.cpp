#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "== valid forms ===" << std::endl;
    try
    {
        Form form1("Tax Form", 50, 25);
        std::cout << form1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== high grade form===" << std::endl;
    try
    {
        Form form2("Invalid Form", 0, 25);
        std::cout << form2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== low grade form ===" << std::endl;
    try
    {
        Form form3("Invalid Form", 50, 151); 
        std::cout << form3 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrat with high enough grade signs form ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 30);
        Form form4("Building Permit", 50, 25);
        
        std::cout << "Before signing: " << form4 << std::endl;
        bob.signForm(form4);
        std::cout << "After signing: " << form4 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Bureaucrat with low grade to sign form ===" << std::endl;
    try
    {
        Bureaucrat john("John", 100);
        Form form5("Top Secret Document", 50, 25);
        
        std::cout << "Before signing attempt: " << form5 << std::endl;
        john.signForm(form5);
        std::cout << "After signing attempt: " << form5 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== grade equal to required ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 50);
        Form form6("Standard Form", 50, 25);
        
        alice.signForm(form6);
        std::cout << form6 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

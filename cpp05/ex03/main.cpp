#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    srand(time(NULL));
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        Bureaucrat boss("Boss", 1);
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
    }

    std::cout << "\n--- Test invalid form ---\n";
    {
        Intern intern;
        AForm* invalid = intern.makeForm("coffee making", "intern");
        if (invalid == NULL)
            std::cout << "Correctly returned NULL for invalid form\n";
    }

    return 0;
}
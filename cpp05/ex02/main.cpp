#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(NULL));

    std::cout << "____Test 1____" << std::endl;
    Bureaucrat br("G", 1);
    ShrubberyCreationForm s1("House");
    br.signForm(s1);
    br.executeForm(s1);

    std::cout << "____Test 2____" << std::endl;
    Bureaucrat weak("W", 140);
    ShrubberyCreationForm s2("garden");
    weak.signForm(s2);
    weak.executeForm(s2); 

    std::cout << "____Test 3____" << std::endl;
    Bureaucrat strong("Strong", 1);
    RobotomyRequestForm robot("Bender");

    strong.signForm(robot);
    strong.executeForm(robot);

    std::cout << "____Test 4___" << std::endl;
    Bureaucrat president("President", 1);
    PresidentialPardonForm pardon("Ford Prefect");

    president.signForm(pardon);
    president.executeForm(pardon);

}

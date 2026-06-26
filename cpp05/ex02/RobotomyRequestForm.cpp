#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm(), target("DefaultTarget"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target_): AForm("RobotomyRequestForm", 72, 45), target(target_){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), target(other.target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    AForm::operator=(other);
    this->target = other.target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    checkExecution(executor);
    std::cout << "Bzzzzz... Drrrrrr... Bzzzzzz...!" << std::endl;
    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized" << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;
}

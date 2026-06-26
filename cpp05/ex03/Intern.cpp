#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &src)
{
	(void)src;
}

Intern::~Intern(){}

Intern &Intern::operator=(const Intern &src)
{
	(void) src;
	return *this;
}

static AForm	*President(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*Robot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*Shrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string formName, const std::string formtarget)
{
	AForm *(*all_forms[])(const std::string target) = {&Shrubbery, &Robot, &President};
	std::string forms[] = {
        "shrubbery creation",
        "robotomy request", 
        "presidential pardon"
    };

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << " now" << std::endl;
			return (all_forms[i](formtarget));
		}
	}
	std::cout << "Intern can not create a form called " << formName << std::endl;
	return (NULL);
}

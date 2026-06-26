#include "AForm.hpp"

AForm::AForm() : name("Default"), is_signed(false), sign_grade(150), execute_grade(150){}

AForm::AForm(const std::string name_, const int sign_grade_, const int execute_grade_) : name(name_), is_signed(false), sign_grade(sign_grade_), execute_grade(execute_grade_)
{
    if (sign_grade_ < 1)
        throw GradeTooHighException();
    if (sign_grade_ > 150)
        throw GradeTooLowException();
    if (execute_grade_ > 150)
        throw GradeTooLowException();
    if (execute_grade_ < 1)
        throw GradeTooHighException();
}

AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), execute_grade(other.execute_grade){}

AForm &AForm::operator=(const AForm &other)
{
	is_signed = other.is_signed;
	return (*this);
}

AForm::~AForm(){}

std::string AForm::getName() const
{
	return name;
}

int AForm::getSignGrade() const
{
	return (sign_grade);
}

bool AForm::getSignedStatus() const
{
	return (is_signed);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= sign_grade)
		is_signed = true;
	else
		throw GradeTooLowException();
}

int AForm::getExecuteGrade() const
{
	return (execute_grade);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, AForm const &AForm)
{
	os << "Name: " << AForm.getName() << " Signed: " << AForm.getSignedStatus() << " Execute Grade: " << AForm.getExecuteGrade() << " SignGrade: " << AForm.getSignGrade();
	return (os);
}

void AForm::checkExecution(Bureaucrat const & executor) const
{
    if (!is_signed)
        throw GradeTooLowException();
    if (executor.getGrade() > execute_grade)
        throw GradeTooLowException();
}

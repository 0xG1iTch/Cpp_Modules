#include "Form.hpp"

Form::Form() : name("Default"), is_signed(false), sign_grade(150), execute_grade(150){}

Form::Form(const std::string name_, const int sign_grade_, const int execute_grade_) : name(name_), is_signed(false), sign_grade(sign_grade_), execute_grade(execute_grade_)
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

Form::Form(const Form &other) : name(other.name), is_signed(other.is_signed), sign_grade(other.sign_grade), execute_grade(other.execute_grade){}

Form &Form::operator=(const Form &other)
{
	is_signed = other.is_signed;
	return (*this);
}

Form::~Form(){}

std::string Form::getName() const
{
	return name;
}

int Form::getSignGrade() const
{
	return (sign_grade);
}

bool Form::getSignedStatus() const
{
	return (is_signed);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= sign_grade)
		is_signed = true;
	else
		throw GradeTooLowException();
}

int Form::getExecuteGrade() const
{
	return (execute_grade);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "Name: " << form.getName() << " isSigned: " << form.getSignedStatus() << " executeGrade: " << form.getExecuteGrade() << " SignGrade: " << form.getSignGrade();
	return (os);
}

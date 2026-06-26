#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        int const sign_grade;
        int const execute_grade;
    public:
        Form();
		Form(const std::string name_, const int sign_grade_, const int execute_grade_);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

        void beSigned(const Bureaucrat &b);
		std::string getName() const;

        bool getSignedStatus() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form const &form);

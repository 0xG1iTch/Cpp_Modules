#pragma once
#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

// class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        int const sign_grade;
        int const execute_grade;
    public:
        AForm();
		AForm(const std::string name_, const int sign_grade_, const int execute_grade_);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

        void beSigned(const Bureaucrat &b);
		std::string getName() const;
        bool getSignedStatus() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		virtual void execute(Bureaucrat const & executor) const = 0;
        
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
	protected:
    	void checkExecution(Bureaucrat const & executor) const;

};

std::ostream &operator<<(std::ostream &os, AForm const &AForm);

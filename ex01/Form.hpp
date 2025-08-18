#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Form
{
public:
	Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	Form(const std::string &name, int sign, int execute);

	void beSigned(const Bureaucrat &Bureaucrat);

	std::string getName() const;
	int getToSign() const;
	int getToExecute() const;
	bool getSigned() const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Grade is too low!";
		}
	};

private:
	const std::string _name;
	bool _signed;
	const int _GradeToSign;
	const int _GradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
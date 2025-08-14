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

	void Form::beSigned(const Bureaucrat &Bureaucrat);

	std::string getName() const;
	int getToSign() const;
	int getToExecute() const;
	std::string getSigned() const;

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
	bool _signed = false;
	const int _GradeToSign;
	const int _GradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
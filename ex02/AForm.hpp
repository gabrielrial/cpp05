#ifndef AFORM_HPP
#define AFORM_HPP

class Bureaucrat;

#include <iostream>
#include <string>

class AForm
{
public:
	AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	AForm(const std::string &name, int sign, int execute, std::string target);

	void beSigned(const Bureaucrat &Bureaucrat);

	std::string getName() const;
	std::string getTarget() const;
	int getToSign() const;
	int getToExecute() const;
	bool getSigned() const;


	void execute(const Bureaucrat &executor) const;
	virtual void action() const = 0;

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

	class NotSignedException : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return "Form is not yet signed";
		}
	};

private:
	const std::string _target;
	const std::string _name;
	bool _signed;
	const int _GradeToSign;
	const int _GradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
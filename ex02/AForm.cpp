#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _target("default"), _name(""), _signed(false), _GradeToSign(150), _GradeToExecute(150) {}

AForm::AForm(const std::string &name, int sign, int execute, std::string target) : _target(target), _name(name), _signed(false), _GradeToSign(sign), _GradeToExecute(execute)
{
	_signed = false;
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other)
	: _name(other._name),
	  _signed(other._signed),
	  _GradeToSign(other._GradeToSign),
	  _GradeToExecute(other._GradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "~AForm" << std::endl;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_GradeToSign)
		throw GradeTooLowException();
	_signed = true;
	std::cout << bureaucrat.getName() << " signed " << AForm::getName() << std::endl;
}

std::string AForm::getTarget() const { return _target; }
std::string AForm::getName() const { return _name; }
int AForm::getToSign() const { return _GradeToSign; }
int AForm::getToExecute() const { return _GradeToExecute; }

bool AForm::getSigned() const { return _signed; }

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form name: " << form.getName()
	   << " | Sign grade: " << form.getToSign()
	   << " | Execute grade: " << form.getToExecute()
	   << " | Status: " << (form.getSigned() ? "signed" : "not signed");
	return os;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > AForm::getToExecute())
		throw GradeTooLowException();
	if (!AForm::getSigned())
		throw NotSignedException();
}

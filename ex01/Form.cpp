#include "Form.hpp"

Form::Form() : _name(""), _signed(false), _GradeToSign(150), _GradeToExecute(150) {}

Form::Form(const std::string &name, int sign, int execute) : _name(name), _signed(false), _GradeToSign(sign), _GradeToExecute(execute)
{
	if (sign > 150 || execute > 150)
		throw GradeTooLowException();
	if (sign < 1 || execute < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other)
	: _name(other._name),
	  _signed(other._signed),
	  _GradeToSign(other._GradeToSign),
	  _GradeToExecute(other._GradeToExecute) {}


Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_GradeToSign)
		throw GradeTooLowException();
	_signed = true;
	std::cout << bureaucrat.getName() << " signed " << Form::getName() << std::endl;
}

std::string Form::getName() const { return _name; }
int Form::getToSign() const { return _GradeToSign; }
int Form::getToExecute() const { return _GradeToExecute; }

bool Form::getSigned() const { return _signed; }

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName()
	   << " | Sign grade: " << form.getToSign()
	   << " | Execute grade: " << form.getToExecute()
	   << " | Status: " << (form.getSigned() ? "signed" : "not signed");
	return os;
}

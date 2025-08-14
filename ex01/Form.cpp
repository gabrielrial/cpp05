#include "Form.hpp"

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_GradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

std::string Form::getName() const { return _name; }
int Form::getToSign() const { return _GradeToSign; }
int Form::getToExecute() const { return _GradeToExecute; }

std::string Form::getSigned() const 
{ 
	if (!_signed)
		return "not signed.";
	else
		return "already signed";
}




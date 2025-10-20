#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout << "Inter default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Inter copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Inter assignment operator called" << std::endl;
	if (this != &other)
	{
		// Copiar atributos aquí
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << "Inter destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string form_name, std::string form_target)
{
	AForm *form = NULL;
	std::string forms[3] = {"presidential request", "robotomy request", "shrubbery request"};

	AForm *(Intern::*makeform[3])(std::string) = {
		&Intern::makePresidential,
		&Intern::makeRobotomyRequest,
		&Intern::makeShrubberyCreation,
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form_name)
		{
			form = (this->*makeform[i])(form_target);
			std::cout << "Intern creates " << form_name << std::endl;
			break;
		}
	}

	if (!form)
		throw std::runtime_error("Form name not found: " + form_name);

	return form;
}
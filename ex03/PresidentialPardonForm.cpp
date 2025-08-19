#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("Pesidential Pardon Form", 25, 5, "default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Pesidential Pardon Form", 25, 5, target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::action() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

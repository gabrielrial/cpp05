#ifndef PRESIDENTIALPARDONFROM_HPP
#define PRESIDENTIALPARDONFROM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	PresidentialPardonForm(std::string target);

	virtual void action() const;

private:
};
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &PresidentialPardonForm);

#endif

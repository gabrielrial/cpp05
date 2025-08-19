#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();

	AForm *makeForm(std::string form_name, std::string form_target);

	AForm *makePresidential(std::string target) { return new PresidentialPardonForm(target); }
	AForm *makeRobotomyRequest(std::string target) { return new RobotomyRequestForm(target); }
	AForm *makeShrubberyCreation(std::string target) { return new ShrubberyCreationForm(target); }

private:
};
std::ostream &operator<<(std::ostream &os, const Intern &Intern);

#endif
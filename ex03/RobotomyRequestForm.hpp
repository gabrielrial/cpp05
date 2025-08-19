#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <ctime>

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	RobotomyRequestForm(std::string target);

	virtual void action() const;

private:
};
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &RobotomyRequestForm);

#endif

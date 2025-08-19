#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		Bureaucrat Rial("Rial", 1);
		AForm *form;
		Intern Gabriel;
		try
		{
			form = Gabriel.makeForm("robotomy request", "Fulanito");
			std::cout << std::endl
					  << *form << std::endl
					  << std::endl;
			form->beSigned(Rial);
			Rial.executeForm(*form);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		delete form;
	}
	{
		Bureaucrat Rial("Rial", 1);
		Intern Gabriel;
		AForm *form;
		try
		{
			form = Gabriel.makeForm("aa request", "Fulanito");
			std::cout << std::endl
					  << *form << std::endl
					  << std::endl;
			form->beSigned(Rial);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}
}

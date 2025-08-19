#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		std::cout << "============================= TEST 00" << std::endl
				  << std::endl;
		AForm *form_1 = new PresidentialPardonForm("Pardon");
		try
		{
			std::cout << *form_1 << std::endl
					  << std::endl;

			Bureaucrat Gabriel("Gabriel", 1);

			form_1->beSigned(Gabriel);
			Gabriel.executeForm(*form_1);
			std::cout << std::endl
					  << *form_1 << std::endl
					  << std::endl;
			Gabriel.increment();
			std::cout << "### We shoud not see this. ###" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl
				  << "============================= END OF TEST 00" << std::endl
				  << std::endl;
		delete form_1;
	}
	std::cout << std::endl
			  << "============================= TEST 01" << std::endl
			  << std::endl;
	{
		try
		{
			Bureaucrat Nora("Gabriela", 200);
			std::cout << "### We shoud not see this. ###" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl
				  << "============================= END OF TEST 01" << std::endl
				  << std::endl;
	}
	{
		std::cout << std::endl
				  << "============================= TEST 02" << std::endl
				  << std::endl;
		AForm *form_2 = new RobotomyRequestForm("Robotomy");
		AForm *form_3 = new ShrubberyCreationForm("Tree");
		try
		{
			Bureaucrat Franklin("Franklin", 72);
			form_2->beSigned(Franklin);
			Franklin.executeForm(*form_2);

			std::cout << "### We shoud not see this. ###" << std::endl;

			Bureaucrat Kars("Kars", 45);
			Kars.executeForm(*form_2);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << std::endl
				  << "============================= END OF TEST 02" << std::endl
				  << std::endl;
				  		std::cout << std::endl
				  << "============================= TEST 03" << std::endl
				  << std::endl;
		try
		{
			Bureaucrat Kars("Kars", 45);
			Kars.executeForm(*form_2);
			std::cout << "### We shoud see this. ###" << std::endl;
			form_3->beSigned(Kars);
			Kars.executeForm(*form_3);
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		delete form_2;
		std::cout << std::endl
		  << "============================= END OF TEST 03" << std::endl
		  << std::endl;
	}
}

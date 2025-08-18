#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form formulario("Test1", 5, 6);
		Bureaucrat Gabriel("Gabriel", 1);

		//formulario.beSigned(Gabriel);
		std::cout << formulario << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	AForm *formulario = new PresidentialPardonForm("hola");
	try
	{

		Bureaucrat Gabriel("Gabriel", 1);

		formulario->beSigned(Gabriel);
		Gabriel.executeForm(*formulario);
		std::cout << *formulario << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	delete formulario;
}

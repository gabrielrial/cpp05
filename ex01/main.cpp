#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form formulario("Test1", 5, 6);
		Bureaucrat b("hola", 280);

		Bureaucrat Gabriel(b);

		formulario.beSigned(Gabriel);
		std::cout << formulario << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

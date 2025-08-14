#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Juan", 2);
		std::cout << b1 << std::endl;

		b1.increment();
		std::cout << "After increment: " << b1 << std::endl;

		// Esto va a lanzar GradeTooHighException
		b1.increment();
		std::cout << "Problem if the code contnues" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "=========================" << std::endl;

	try
	{
		// Esto va a lanzar GradeTooLowException en el constructor
		Bureaucrat b2("Maria", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Excepción atrapada: " << e.what() << std::endl;
	}

	return 0;
}

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Bob", 150);
		std::cout << b1 << std::endl;

		b1.decrement();
		std::cout << "After decrement: " << b1 << std::endl;

		std::cout << "Problem if the code continues" << std::endl;
		b1.increment();
	}
	catch (std::exception & e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "=========================" << std::endl;

	try
	{
		Bureaucrat b2("Maria", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "=========================" << std::endl;

	try
	{
		// Esto va a lanzar GradeTooLowException en el constructor
		Bureaucrat b3("Maria", 149);
		b3.increment();
		b3.increment();
		std::cout << "After 2 increment: " << b3 << std::endl;
		b3.decrement();
		b3.decrement();
		std::cout << "After 2 decrement: " << b3 << std::endl;
		b3.decrement();
		std::cout << "After decrement: " << b3 << std::endl;
		b3.decrement();
		std::cout << "Problem if the code continues" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}

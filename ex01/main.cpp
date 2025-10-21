#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form form("Form", 5, 6);
		Bureaucrat gabriel("Gabriel", 1);
		Bureaucrat minion("Esbirro", 150);

		std::cout << form << std::endl << std::endl;
		minion.singForm(form);
		std::cout << form << std::endl << std::endl;

		gabriel.singForm(form);
		std::cout << form << std::endl << std::endl;

		gabriel.singForm(form);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

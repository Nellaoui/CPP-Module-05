#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat op("noman" , 150);
		Form l("alo", 1, 10);
		std::cout <<  "name : " << l << std::endl;
		l.beSigned(l);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

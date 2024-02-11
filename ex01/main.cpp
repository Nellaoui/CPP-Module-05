#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat op("noman" , 150);
		Form l("alo", 10, 10);
		std::cout <<  "name : " << l << std::endl;
		l.beSigned(op);
		l.beSigned(op);
		l.beSigned(op);
		l.beSigned(op);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

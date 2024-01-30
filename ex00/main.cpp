#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat op("noman" , 150);
		std::cout <<  "name : " << op << std::endl;
		op.decrementGrade();
		op.incrementGrade();
		op.decrementGrade();
		op.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

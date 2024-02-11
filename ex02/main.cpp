#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void Robotomy()
{
	RobotomyRequestForm robotomyForm("TargetName");

	Bureaucrat bureaucrat("John", 10);
	try
	{
		robotomyForm.beSigned(bureaucrat);
		robotomyForm.execute(bureaucrat);
		bureaucrat.executeForm(robotomyForm);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}


void	shrubbery()
{
	Bureaucrat bob("Bob", 5);
	ShrubberyCreationForm shrubberyForm("Garden");
	try
	{
		bob.signAForm(shrubberyForm);
		std::cout << shrubberyForm.GetSingingStatus() << "|\n";
		shrubberyForm.execute(bob);
		bob.executeForm(shrubberyForm);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Presidentail()
{
	Bureaucrat bureaucrat("bob", 15);
	PresidentialPardonForm op("pardon");
	try
	{
		bureaucrat.signAForm(op);
		op.execute(bureaucrat);
		bureaucrat.executeForm(op);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

int main()
{
	std::cout << "_______________________ Presidentail Pardon Form _________________\n";
	Presidentail();
	std::cout << "_____________________ Robotomy___________________\n";
	Robotomy();
	std::cout << "_____________________ shrubbery___________________\n";
	shrubbery();
	return 0;
}



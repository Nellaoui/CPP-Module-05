#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & __unused rhs )
{
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Intern const & __unused i)
{
	// o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *Intern::creatPresidential(const std::string &target)
{
	try
	{
		PresidentialPardonForm *form;

		form = new PresidentialPardonForm(target);
		std::cout << "Intern creates : " << form->getName() << std::endl;
		return form;
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Faild To allocate memory" << e.what() << std::endl;
		return NULL;
	}
}

AForm *Intern::creatShrubbery(const std::string &target)
{
	try
	{
		ShrubberyCreationForm *form;
		form = new ShrubberyCreationForm(target);
		std::cout << "Intern creates : " << form->getName() << std::endl;
		return form;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << "Faild To allocate memory" << e.what() << std::endl;
		return NULL;
	}

}

AForm *Intern::creatRobotomy(const std::string &target)
{
	try
	{
		RobotomyRequestForm *form;
		form = new RobotomyRequestForm(target);
		std::cout << "Intern Creates : " << form->getName() << std::endl;
		return form;
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}

	// return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	pointerToMemberFunction function[3];
	std::string name[3];

	function[0] = &Intern::creatPresidential;
	function[1] = &Intern::creatRobotomy;
	function[2] = &Intern::creatShrubbery;
	name[0] = "Presidential";
	name[1] = "Robotomy";
	name[2] = "Shrubbery";

	for (size_t i = 0; i < 3; i++)
	{
		if (formName.find(name[i]) != std::string::npos)
			return (function[i](target));

	}
	return __null;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

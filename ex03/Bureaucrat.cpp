#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("donpha") , _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();

}
Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	this->_grade = src._grade;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << " bureaucrat grade " << i.getGrade() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void Bureaucrat::incrementGrade()
{
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signAForm(AForm &AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << this->getName() << " signed " << AForm.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << " Bureaucrat " << this->_name << " couldn`t sign " <<  AForm.getName() << " because :" << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << " Bureaucrat " << this->_name << " couldn`t execute " <<  form.getName() << " because :" << std::endl;
		std::cerr << e.what() << '\n';
	}

}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}
/* ************************************************************************** */

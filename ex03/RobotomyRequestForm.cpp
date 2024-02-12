#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45) , _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & __unused i)
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->GetSingingStatus())
	{
		if (executor.getGrade() <= this->getGradeRequired())
		{
			srand(time(0));
			std::cout << " DRRRRRRRRRRR 💥 " << std::endl;
			int a = rand();
			if ((a % 2))
				std::cout << _target << " has been robotomized successfully  50% of the time ✅" << std::endl;
			else
				std::cerr << _target << " that the robotomy failed ❌" << std::endl;
		}
		else
		{
			std::cerr << "Shrubbery form can't execute because of : " << std::endl;
			throw GradeTooHighException();
		}
	}
	else
		std::cerr << "Form is not signed, cannot execute this 😞" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) , _target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & __unused i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	if (this->GetSingingStatus())
	{
		if (this->getGradeExecute() <= this->getGradeRequired())
		{
			std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		}
		else
		{
			std::cerr << "PresidentialPardon form can't execute because of : ";
			throw GradeTooHighException();
		}
	}
	else
		std::cerr << "the forum must be singed 🚨" << std::endl;

}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */

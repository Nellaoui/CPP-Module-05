#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : _name("donpha"), _singingStatus(false)  , _gradeRequired(1), _gradeExecute(1)
{
}

AForm::AForm(std::string name, const int gradeRequired, const int gradeExecute) : _name(name),   _gradeRequired(gradeRequired) , _gradeExecute(gradeExecute)
{
	if (gradeRequired > 150 || gradeExecute > 150)
		throw GradeTooLowException();
	if (gradeRequired < 1 || gradeExecute < 1)
		throw GradeTooHighException();
}

AForm::AForm( const AForm & src ) : _name(src._name) , _gradeRequired(src._gradeRequired), _gradeExecute(src._gradeExecute)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_singingStatus = rhs._singingStatus;
	}
	return *this;
}

std::ostream	&operator<<( std::ostream &o, AForm const & i )
{
	o << i.getName() << " bureaucrat grade " << i.getGradeExecute() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (!this->_singingStatus)
	{
		if (bureaucrat.getGrade() <= getGradeRequired())
			this->_singingStatus = true;
		else
			throw GradeTooLowException();
	}

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string AForm::getName() const
{
	return _name;
}
int AForm::getGradeRequired() const
{
	return _gradeRequired;
}
int AForm::getGradeExecute() const
{
	return _gradeExecute;
}
bool AForm::GetSingingStatus() const
{
	return _singingStatus;
}

/* ************************************************************************** */

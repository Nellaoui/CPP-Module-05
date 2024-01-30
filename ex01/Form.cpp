#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("donpha"), _singingStatus(1), _gradeRequired(10)
{
}

Form::Form(std::string name, bool sign, int grade) : _name(name), _singingStatus(sign), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Form::Form( const Form & src ) : _name(src._name) , _singingStatus(src._singingStatus), _grade(src._grade)
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		// this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << i.getName() << " bureaucrat grade " << i.getGradeExecute() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= getGradeRequired())
		this->_singingStatus = true;
	else
		throw GradeTooLowException();

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string Form::getName() const
{
	return _name;
}
int Form::getGradeRequired() const
{
	return _gradeRequired;
}
int Form::getGradeExecute() const
{
	return _gradeExecute;
}
bool Form::GetSingingStatus() const
{
	return _singingStatus;
}

/* ************************************************************************** */

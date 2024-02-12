#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs._target;
	}
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->GetSingingStatus())
	{
		if (executor.getGrade() <= this->getGradeRequired())
		{
			std::ofstream outputFile(_target + "_shrubbery");
			if (outputFile.is_open())
			{
				outputFile << "          .     .  .      +     .      .          .\n";
				outputFile << "     .       .      .     #       .           .\n";
				outputFile << "        .      .         ###            .      .      .\n";
				outputFile << "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n";
				outputFile << "          .      . \"####\"###\"####\"  .\n";
				outputFile << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n";
				outputFile << "  .             \"#########\"#########        .        .\n";
				outputFile << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n";
				outputFile << "     .     .  \"#######\"##\"#####\"##\"#######\"                  .\n";
				outputFile << "                .\"##\"#####\"#####\"##\"           .      .\n";
				outputFile << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n";
				outputFile << "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n";
				outputFile << "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n";
				outputFile << "            .     \"      000      \"    .     .\n";
				outputFile << "       .         .   .   000     .        .       .\n";
				outputFile << ".. .. ..................O000O........................ ...... ...\n";
				std::cout << "Shrubbery Creation Form executed successfully by " << executor.getName() << "!" << std::endl;
			}
			else
				std::cerr << "Error: Unable to open the file for Shrubbery Creation Form." << std::endl;
		}
		else
		{
			std::cerr << "Shrubbery form can't execute because of : ";
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

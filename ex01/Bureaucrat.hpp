#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;
class Bureaucrat
{

	public:

		class GradeTooHighException : public std::exception
		{
			public :
				const char *what() const throw()
				{
					return "Grade Is Too High! ⬆️";
				}
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char *what() const throw()
				{
					return "Grade Is Too Low! ⬇️";
				}
		};
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &Form);
		Bureaucrat &		operator=( Bureaucrat const & rhs );

	private:
	const std::string _name;
	int _grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */

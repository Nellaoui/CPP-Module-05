#ifndef Form_HPP
# define Form_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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
		Form();
		Form(std::string name,const int gradeRequired, const int gradeExecute);
		Form( Form const & src );

		~Form();

	const std::string getName() const;
	int getGradeRequired() const;
	int getGradeExecute() const;
	bool GetSingingStatus() const;

    void beSigned(Bureaucrat &bureaucrat);

		Form &		operator=( Form const & rhs );

	private:
		const std::string _name;
		bool _singingStatus;
		const int _gradeRequired;
		const int _gradeExecute;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ Form_H */

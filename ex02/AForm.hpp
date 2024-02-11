#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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
		AForm();
		AForm(std::string name,const int gradeRequired, const int gradeExecute);
		AForm( AForm const & src );

		virtual	~AForm() = 0;

	const std::string getName() const;
	int getGradeRequired() const;
	int getGradeExecute() const;
	bool GetSingingStatus() const;

	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	AForm &		operator=( AForm const & rhs );

	private:
		const std::string _name;
		bool _singingStatus;
		const int _gradeRequired;
		const int _gradeExecute;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AForm_H */

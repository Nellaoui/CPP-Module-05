#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"


class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & __unused rhs );

		AForm *makeForm(const std::string &formName, const std::string &target);

	private:
		static AForm *creatPresidential(const std::string &target);
		static AForm *creatShrubbery(const std::string &target);
		static AForm *creatRobotomy(const std::string &target);

};

std::ostream &			operator<<( std::ostream & o, Intern const & i );

typedef AForm *(*pointerToMemberFunction) (const std::string &target);

#endif /* ********************************************************** INTERN_H */

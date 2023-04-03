#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &to_copy);
		
		~Intern(void);

		Intern& operator=(const Intern &assign);

		AForm *makeForm(std::string name, std::string target);		
};

#endif // INTERN_HPP
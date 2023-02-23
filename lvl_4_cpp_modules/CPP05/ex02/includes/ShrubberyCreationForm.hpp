#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : AForm {
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);
		~ShrubberyCreationForm(void);


	private:
		const int grade_to_sign;
		const int grade_to_execute;
};

#endif // SHRUBBERYCREATIONFORM_HPP
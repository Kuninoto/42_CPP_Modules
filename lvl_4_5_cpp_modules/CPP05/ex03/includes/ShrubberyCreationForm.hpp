#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& to_copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);
		~ShrubberyCreationForm(void);

		void executeSuperClassForm(Bureaucrat const& executor) const;

	private:
		ShrubberyCreationForm(void);
};

#endif // SHRUBBERYCREATIONFORM_HPP
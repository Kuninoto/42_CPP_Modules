#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm(void);

		PresidentialPardonForm& operator=(const PresidentialPardonForm &assign);

		void executeSuperClassForm(Bureaucrat const& executor) const;

	private:
		PresidentialPardonForm(void);
};

#endif // PRESIDENTIALPARDONFORM_HPP
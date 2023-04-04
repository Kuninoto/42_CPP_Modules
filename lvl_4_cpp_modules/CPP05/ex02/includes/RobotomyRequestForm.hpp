#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &to_copy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm& operator=(const RobotomyRequestForm &assign);

		void executeSuperClassForm(Bureaucrat const& executor) const;

		private:
			RobotomyRequestForm(void);
};

#endif // ROBOTOMYREQUESTFORM_HPP
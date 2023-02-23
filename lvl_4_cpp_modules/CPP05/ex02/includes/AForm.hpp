#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <string>
# include "Bureaucrat.hpp"

using std::string;

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class AForm {
	public:
		AForm(void);
		AForm(string name, int grade_to_sign, int grade_to_execute);
		virtual AForm &operator=(const AForm &original);
		virtual ~AForm(void);

		virtual const string getName(void);
		virtual bool getSignState(void);
		virtual int getGradeToSign(void);
		virtual int getGradeToExecute(void);

		virtual void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;
};

std::ostream &operator<<(std::ostream &stream, AForm &form);

#endif // AFORM_HPP
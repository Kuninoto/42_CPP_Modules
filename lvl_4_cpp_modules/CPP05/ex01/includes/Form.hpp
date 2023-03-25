#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <string>
# include "Bureaucrat.hpp"

using std::string;

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Form {
	public:
		Form(void);
        Form(const Form& to_copy);
		Form(string name, int grade_to_sign, int grade_to_execute);
		Form &operator=(const Form &original);
		~Form(void);

		const string getName(void);
		bool getSignState(void);
		int getGradeToSign(void);
		int getGradeToExecute(void);

		void beSigned(Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &stream, Form &Form);

#endif // FORM_HPP
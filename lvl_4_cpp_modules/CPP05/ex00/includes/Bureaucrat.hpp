#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>
using std::string;

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& to_copy);
		Bureaucrat(string name, int grade);
		Bureaucrat &operator=(const Bureaucrat &original);
		~Bureaucrat(void);

		string const getName(void);
		int getGrade(void);

		void setGrade(int grade);

		void incrementGrade(void);
		void decrementGrade(void);

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
		string const name;
		int grade;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat);

#endif // BUREAUCRAT_HPP
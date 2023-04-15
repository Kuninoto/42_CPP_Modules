#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
    public:
        Bureaucrat(void);
        Bureaucrat(const Bureaucrat& to_copy);
        Bureaucrat(std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &original);
        ~Bureaucrat(void);

        const std::string& getName(void) const;
        int getGrade(void) const;

        void setGrade(int grade);

        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(std::string form_name, bool was_signed);

        void executeForm(AForm const& form);

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
        const std::string name;
        int grade;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bureaucrat);

#endif // BUREAUCRAT_HPP
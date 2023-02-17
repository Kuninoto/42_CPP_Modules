#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
using std::string;

class BureauCrat {
	public:
		BureauCrat();

		string const getName();
		size_t getGrade();

		void incrementGrade();
		void decrementGrade();

	private:
		string const name;
		size_t grade;
};

#endif // BUREAUCRAT_HPP
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
using std::string;

class Brain {
	public:
		Brain(void);
		Brain(const Brain &to_copy);
		Brain &operator=(const Brain &to_copy);
		~Brain(void);

	private:
		string ideas[100];
};

#endif // BRAIN_HPP
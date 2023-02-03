#ifndef HARL_HPP
# define HARL_HPP

# include <string>
using std::string;

class Harl {
	public:
		Harl(void);
		~Harl(void);
		void complain(string level);
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

typedef void (Harl::*harl_func_t) (void);
#endif // HARL_HPP
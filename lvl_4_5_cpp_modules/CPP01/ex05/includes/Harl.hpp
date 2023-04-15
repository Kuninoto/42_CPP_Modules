#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {
	public:
		Harl(void);
		~Harl(void);
		void complain(std::string level);

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

//      Return_Type (Class_Name::* pointer_name) (Argument_List);
typedef void (Harl::* harl_func_t) (void);

#endif // HARL_HPP
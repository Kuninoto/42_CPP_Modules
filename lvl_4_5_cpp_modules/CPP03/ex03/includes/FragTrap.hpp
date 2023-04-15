#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(string name);
		~FragTrap(void);

		void highFivesGuys(void);
	private:
};

#endif // FRAGTRAP_HPP
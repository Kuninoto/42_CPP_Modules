#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap(void);

		void highFivesGuys(void);

	private:
		FragTrap(void);
};

#endif // FRAGTRAP_HPP
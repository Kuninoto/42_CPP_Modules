#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap 
{
	public:
		ScavTrap(void);
		ScavTrap(string name);
		~ScavTrap(void);

		void attack(const string& target);
		void guardGate(void);
	private:
};

#endif // SCAVTRAP_HPP
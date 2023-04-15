#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
	public:
		ScavTrap(string name);
		~ScavTrap(void);

		void attack(const string& target);
		void guardGate(void);
	private:
		ScavTrap(void);
};

#endif // SCAVTRAP_HPP
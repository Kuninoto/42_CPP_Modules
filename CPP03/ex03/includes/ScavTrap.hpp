#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap 
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		~ScavTrap(void);

		void attack(const std::string& target);
		void guardGate(void);

		static const int defaultHitPoints = 100;
		static const int defaultEnergyPoints = 50;
		static const int defaultAttackDamage = 20;
};

#endif // SCAVTRAP_HPP
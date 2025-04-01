#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string name);
		~ScavTrap(void);

		void attack(const std::string& target);
		void guardGate(void);

	private:
		ScavTrap(void);
};

#endif // SCAVTRAP_HPP
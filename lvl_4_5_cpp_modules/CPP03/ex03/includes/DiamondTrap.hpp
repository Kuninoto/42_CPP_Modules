#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &original);
		DiamondTrap &operator=(const DiamondTrap &original);
		~DiamondTrap(void);

		using ScavTrap::attack;
		void whoAmI(void);

	private:
		std::string name;
};

#endif // DIAMONDTRAP_HPP
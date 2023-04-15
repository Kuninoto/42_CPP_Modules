#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &to_copy);
		ClapTrap& operator=(const ClapTrap &original);
		~ClapTrap(void);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;
};

#endif // CLAPTRAP_HPP
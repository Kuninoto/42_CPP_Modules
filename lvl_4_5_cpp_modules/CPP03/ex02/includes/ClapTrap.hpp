#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
using std::string;

class ClapTrap
{
	public:
		ClapTrap(string name);
		ClapTrap(const ClapTrap &to_copy);
		ClapTrap& operator=(const ClapTrap &original);
		~ClapTrap(void);

		void attack(const string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected:
		string name;
		unsigned int hit_points;
		unsigned int energy_points;
		unsigned int attack_damage;
};

#endif
#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack(void);

	private:
		std::string name;
		Weapon *weapon;
};

#endif // HUMAN_B_HPP
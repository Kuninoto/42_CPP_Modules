#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <string>
# include "Weapon.hpp"

using std::string;

class HumanB {
	private:
		string name;
		Weapon *weapon;
	public:
		HumanB(string name);
		void setWeapon(Weapon &weapon);
		void attack(void);
};

#endif // HUMAN_B_HPP
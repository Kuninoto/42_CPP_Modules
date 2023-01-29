#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <string>
# include "Weapon.hpp"

using std::string;

class HumanA {
	private:
		string name;
		Weapon &weapon;
	public:
		HumanA(string name, Weapon &weapon);
		void attack(void);
};

#endif // HUMAN_A_HPP
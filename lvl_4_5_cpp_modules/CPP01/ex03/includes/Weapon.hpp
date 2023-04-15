#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
using std::string;

class Weapon {
	public:
		Weapon(string type);
		string const &getType(void);
		void setType(string type);
	private:
		string type;
};

#endif // WEAPON_HPP
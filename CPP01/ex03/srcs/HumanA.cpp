#include <iostream>
#include "HumanA.hpp"

using std::cout;
using std::endl;

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

void HumanA::attack(void) {
	cout << this->name << " attacks with their " << this->weapon.getType() << endl;
}

#include <iostream>
#include "HumanB.hpp"

using std::cout;
using std::endl;

HumanB::HumanB(string name) : name(name) {}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack(void) {
	cout << this->name << " attacks using their " << weapon->getType() << endl;
}

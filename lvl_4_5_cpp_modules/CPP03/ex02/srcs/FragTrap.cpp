#include <iostream>
#include "FragTrap.hpp"

using std::cout;
using std::endl;

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	cout << "Sub Class (FragTrap) constructor has been called" << endl;
}

FragTrap::~FragTrap(void) {
	cout << "Sub Class (FragTrap) destructor has been called" << endl;
}

void FragTrap::highFivesGuys(void) {
	if (this->energy_points == 0) {
        cout << "FragTrap "<< this->name << " is out of energy points!" << endl;
        return;
    }
	cout << "FragTrap " << this->name << " says: High Fives!" << endl;
    this->energy_points -= 1;
}

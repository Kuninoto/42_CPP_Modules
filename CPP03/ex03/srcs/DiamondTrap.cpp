#include <iostream>
#include "DiamondTrap.hpp"

using std::cout;
using std::endl;

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap() {};

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    this->name = name;
    this->hit_points = FragTrap::defaultHitPoints;
    this->energy_points = ScavTrap::defaultEnergyPoints;
    this->attack_damage = FragTrap::defaultAttackDamage;

    cout << "Sub Class (DiamondTrap) constructor has been called" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original)
: ClapTrap(original), FragTrap(original), ScavTrap(original)
{
	*this = original;
	cout << "Sub Class (DiamondTrap) copy constructor has been called" << endl; 
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
	this->name = original.name;
	ClapTrap::name = (this->name + "_clap_name");
	this->hit_points = original.hit_points;
	this->energy_points = original.energy_points;
	this->attack_damage = original.attack_damage;

	cout << "Sub Class (DiamondTrap) Assignment operator called" << endl;
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
    cout << "Sub Class (DiamondTrap) destructor has been called" << endl;
}

void DiamondTrap::whoAmI(void) {
	cout << "I AM:\nDiamondTrap: " << this->name << "\nClapTrap: " << ClapTrap::name << endl;
}

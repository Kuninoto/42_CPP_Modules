#include <iostream>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap(string name)
: name(name), hit_points(10), energy_points(10), attack_damage(0) {
	cout << "Default constructor has been called!" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &to_copy)
{
	this->name = to_copy.name;
	this->hit_points = to_copy.hit_points;
	this->energy_points = to_copy.energy_points;
	this->attack_damage = to_copy.attack_damage;
	cout << "Copy constructor has been called!" << endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &original)
{
	if (this != &original)
	{
		this->name = original.name;
		this->hit_points = original.hit_points;
		this->energy_points = original.energy_points;
		this->attack_damage = original.attack_damage;
	}
	cout << "Copy assignment constructor has been called!" << endl;
	return *this;
}

ClapTrap::~ClapTrap(void) {
	cout << "Destructor has been called" << endl;
};

void ClapTrap::attack(const string& target)
{
	cout << "ClapTrap " << this->name 
	     << " attacks " << target 
		 << " causing <amount> " 
		 << "points of damage!" << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->hit_points || this->hit_points == 0)
	{
		cout << "ClapTrap " << this->name << " died" << endl;
		this->hit_points = 0;
		return;
	}
	else if (this->energy_points == 0)
	{
		cout << "ClapTrap has no energy points left!" << endl;
		return;
	}
	this->hit_points -= amount;
	this->energy_points -= 1;
	cout << "ClapTrap " << this->name
		 << " took " << amount << " points of damage" << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0)
	{
		cout << "ClapTrap has no energy points left!" << endl;
		return ;
	}
	this->hit_points += amount;
	this->energy_points -= 1;
	cout << "ClapTrap " << this->name
		 << " has been repaired and gained "
		 << amount << " hit points" << endl;
}

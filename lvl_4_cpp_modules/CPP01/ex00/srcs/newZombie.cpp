#include <iostream>
#include "Zombie.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Zombie *newZombie(string name)
{
    Zombie *new_zombie = new Zombie;

    new_zombie->setName(name);
    return new_zombie;
}

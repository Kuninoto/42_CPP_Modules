#include "Zombie.hpp"

using std::string;

void randomChump(string name)
{
    Zombie new_zombie;

    new_zombie.setName(name);
    new_zombie.announce(); 
}

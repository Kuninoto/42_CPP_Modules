#include "Zombie.hpp"
#include <string>

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie *zombie_array = new Zombie[N];

    for (int i = 0; i < N; i += 1)
        zombie_array[i].setName(name);
    return (zombie_array);
}

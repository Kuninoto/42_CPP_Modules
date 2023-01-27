#include "Zombie.hpp"
#include <iostream> // std::string, std::cin, std::cout, std::endl

using std::string;
using std::cin;
using std::cout;
using std::endl;

Zombie  *zombieHorde(int N, string name)
{
    Zombie *zombie_array = new Zombie[N];

    for (int i = 0; i < N; i += 1)
        zombie_array[i].setName(name);
    return (zombie_array);
}

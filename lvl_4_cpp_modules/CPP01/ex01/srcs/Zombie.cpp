#include "Zombie.hpp"
#include <iostream> // std::cout, std::endl

using std::string;
using std::cout;
using std::endl;

/* Destructor */
Zombie::~Zombie(void) {
    cout << "Zombie " << getName() << " died 💀" << endl;
}

void Zombie::setName(string name) {
    this->name = name;
}

string Zombie::getName(void) {
    return this->name;
}

void Zombie::announce(void) {
    cout << getName() << ": BraiiiiiiinnnzzzZ..." << endl;
}

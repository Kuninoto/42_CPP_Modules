#include "Zombie.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Zombie::~Zombie(void) {
    cout << "Zombie " << this->getName() << " died 💀" << endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

const std::string& Zombie::getName(void) const {
    return this->name;
}

void Zombie::announce(void) {
    cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << endl;
}

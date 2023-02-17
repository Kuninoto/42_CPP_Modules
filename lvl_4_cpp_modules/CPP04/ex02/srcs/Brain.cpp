#include <iostream>
#include "Brain.hpp"

using std::cout;
using std::endl;

Brain::Brain(void) {
	cout << "[Brain] default constructor has been called" << endl;
};

Brain::Brain(const Brain &to_copy)
{
	*this = to_copy;
	cout << "[Brain] copy constructor has been called" << endl;
}

Brain& Brain::operator=(const Brain &to_copy)
{
	if (this != &to_copy)
	{
		for (size_t i = 0; i < 100; i += 1) {
			this->ideas[i] = to_copy.ideas[i];
		}
	}
	cout << "[Brain] copy assignment constructor has been called" << endl;
	return *this;
}

Brain::~Brain(void) {
	cout << "[Brain] default destructor has been called" << endl;
}

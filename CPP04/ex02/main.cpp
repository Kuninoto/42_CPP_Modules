#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>
#include <iostream>

#define NBR_ANIMALS 4

using std::cout;
using std::endl;

int main(void)
{
//	AAnimal	test = new AAnimal();

	const AAnimal* Bisteca = new Dog();
	cout << endl;

	const AAnimal* Junim = new Cat();
	cout << endl;

	cout << "------------------- ZOO -------------------" << endl;
	const AAnimal* zoo[NBR_ANIMALS];

	cout << "------------------- DOGS -------------------" << endl;
	for (size_t i = 0; i < 2; i += 1) {
		zoo[i] = new Dog();
		cout << endl;
	}

	cout << "------------------- CATS -------------------" << endl;
	for (size_t i = 2; i < 4; i += 1) {
		zoo[i] = new Cat();
		cout << endl;
	}

	cout << "---------------- DELETE ZOO ---------------" << endl;
	for (size_t i = 0; i < NBR_ANIMALS; i += 1) {
		delete zoo[i];
	}
	cout << "--------------- ZOO DELETED ---------------" << endl;
	cout << endl;

	delete Bisteca;
	delete Junim;

	return EXIT_SUCCESS; 
}

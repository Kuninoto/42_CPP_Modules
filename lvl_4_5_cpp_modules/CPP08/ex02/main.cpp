#include <iostream>
#include <cstdlib>
#include "MutantStack.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);

	MutantStack<int>::iterator begin = ms.begin();
	MutantStack<int>::iterator end = ms.end();

	cout << "stack = ";
	while (begin != end)
	{
		cout << *begin << " ";
		begin += 1;
	}

	cout << endl;
	return EXIT_SUCCESS;
}

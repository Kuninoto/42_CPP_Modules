#include <iostream> // std::string, std::cin, std::cout, std::endl
#include <cstdlib> // EXIT_* MACROS
#include "Harl.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	Harl harl;
	string input;

	while (1)
	{
		cout << "Enter a level for Harl 🤓: ";
		getline(cin, input);
		if (input.empty())
			continue;
		harl.complain(input);
	}
	return EXIT_SUCCESS;	
}
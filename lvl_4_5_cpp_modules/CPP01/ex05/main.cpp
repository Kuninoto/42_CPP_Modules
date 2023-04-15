#include <iostream> // std::string, std::cin, std::cout, std::endl
#include <cstdlib> // EXIT_* MACROS
#include <stdio.h> // clearerr()
#include "Harl.hpp"

using std::cin;
using std::cout;
using std::endl;

bool isInputValid(const std::string& input)
{
	if (input != "DEBUG" && input != "INFO"
	&& input != "WARNING" && input != "ERROR")
	{
		cout << "Please insert a valid level for Harl 🤓" << endl;
		return false;
	}
	return true;
}

int main(void)
{
	Harl harl;
	std::string input;

	while (1)
	{
		cout << "Enter a level for Harl 🤓: ";
		getline(cin, input);
		if (cin.eof() == true)
        {
            cin.clear();
            clearerr(stdin);
			cout << endl;
        }
		if (input.empty() || !isInputValid(input))
			continue;
		harl.complain(input);
	}
	return EXIT_SUCCESS;
}

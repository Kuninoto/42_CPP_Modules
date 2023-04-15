#include <iostream> // std::string, std::cin, std::cout, std::endl
#include <cstdlib> // EXIT_* MACROS
#include "Harl.hpp"

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2 || !argv[1])
	{
		cerr << "Invalid arguments" << endl;
		cout << "Usage: ./harlFilter <level>" << endl;
		return EXIT_FAILURE;
	}
	harl.complain(argv[1]);	
	return EXIT_SUCCESS;
}

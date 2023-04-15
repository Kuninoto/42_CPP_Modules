#include <iostream> // std::cerr, std::cout, std::endl
#include <cstdlib> // EXIT_* MACROS
#include "Harl.hpp"

using std::cerr;
using std::cout;
using std::endl;

#define ARGC_ERR "Invalid arguments"
#define USAGE "Usage: ./harlFilter <level>\nlevels: DEBUG, INFO, WARNING, ERROR"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2 || !argv[1])
	{
		cerr << ARGC_ERR << '\n';
		cout << USAGE << endl;
		return EXIT_FAILURE;
	}
	harl.complain(argv[1]);	
	return EXIT_SUCCESS;
}

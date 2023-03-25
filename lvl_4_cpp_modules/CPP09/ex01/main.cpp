#include <cstdlib>
#include <stack>
#include <sstream>
#include <string>
#include "RPN.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cerr << "RPN: error: " << "invalid number of arguments" << endl;
		return EXIT_FAILURE;
	}

	RPN calc;
	if (!calc.valid_expression(argv[1]))
	{
		cerr << "RPN: error: " << "invalid expression" << endl;
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}

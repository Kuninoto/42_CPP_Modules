#include <cstdlib>
#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cerr << "btc: error:" << "could not open file" << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

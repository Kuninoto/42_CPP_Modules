#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

using std::cerr;
using std::endl;

int	main(int argc, char **argv)
{
    if (argc != 2 || !argv[1][1])
    {
        cerr << "Usage: ./convert <literal>" << endl;
        return EXIT_FAILURE;
    }
    ScalarConverter::convert(argv[1]);
    return EXIT_SUCCESS;
}

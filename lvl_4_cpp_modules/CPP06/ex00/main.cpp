#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cerr;
using std::endl;

int	main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: ./convert " << endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

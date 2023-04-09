#include <cstdlib>
#include <iostream>
#include "PmergeMe.hpp"

using std::cout;
using std::cerr;
using std::endl;

/* 
# define ERROR_MSG_PREFFIX "PmergeMe: error: "

static int panic(const std::string& error_msg)
{
    cerr << ERROR_MSG_PREFFIX << error_msg << '\n';
    return EXIT_FAILURE;
} */

int main(int argc, char **argv)
{
	if (argc == 1)
	    return EXIT_SUCCESS;
    PmergeMe pmm;

    // MISSING DUPLICATE CHECK
    // && refactor this
    try {
        for (size_t i = 0; argv[i]; i += 1)
            if (std::string(argv[i]).find_first_not_of("0123456789 ") != std::string::npos)
			    throw PmergeMe::InvalidElementException();
    }
    catch (std::exception& e) {
        cerr << e.what() << '\n';
    }

	return EXIT_SUCCESS;
}

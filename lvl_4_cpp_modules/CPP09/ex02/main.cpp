#include <cstdlib>
#include <iostream>
#include "PmergeMe.hpp"

using std::cout;
using std::cerr;
using std::endl;

# define ERROR_MSG_PREFFIX "RPN: error: "
# define ARGC_ERR "invalid number of arguments"
# define INVALID_EXPR_ERR "invalid expression"

static int panic(const std::string& error_msg)
{
    cerr << ERROR_MSG_PREFFIX << error_msg << '\n';
    return EXIT_FAILURE;
}

int main(int argc, char **argv)
{
	if (argc != 2)
        return panic(ARGC_ERR);

	return EXIT_SUCCESS;
}

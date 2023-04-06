#include <cstdlib>
#include <iostream>
#include <sstream>
#include "RPN.hpp"

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

	if (!RPN::valid_expression(argv[1]))
        return panic(INVALID_EXPR_ERR);

    cout << RPN::calculate(argv[1]) << endl;
	return EXIT_SUCCESS;
}

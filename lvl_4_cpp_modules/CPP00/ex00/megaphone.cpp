#include <iostream> // std::string, cout, endl
#include <cstdlib> // EXIT_* macros

using std::string;
using std::cout;
using std::endl;

string string_to_upper(string arg)
{
    for (size_t i = 0; i < arg.length(); i += 1)
        arg[i] = toupper(arg[i]);
    return arg;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
        return EXIT_SUCCESS;
    }
    for (int i = 1; i < argc; i += 1)
        cout << string_to_upper(argv[i]);
    cout << endl;
    return EXIT_SUCCESS;
}
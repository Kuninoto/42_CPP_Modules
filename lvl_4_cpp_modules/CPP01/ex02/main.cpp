#include <iostream> // std::string, std::cout, std::endl
#include <cstdlib> // EXIT_* MACROS

using std::string;
using std::cout;
using std::endl;

int main(void)
{
    string stringOG = "HI THIS IS BRAIN";
    string *stringPTR = &stringOG;
    string &stringREF = stringOG;

    cout << "Address of stringOG = " << &stringOG << endl;
    cout << "Thru pointer value = " << stringPTR << endl;
    cout << "Thru reference value = " << &stringREF << endl;

    cout << endl;

    cout << "Value of stringOG = " << stringOG << endl;
    cout << "Thru pointer dereferencing = " << *stringPTR << endl;
    cout << "Thru reference = " << stringREF << endl;

    return EXIT_SUCCESS;
}

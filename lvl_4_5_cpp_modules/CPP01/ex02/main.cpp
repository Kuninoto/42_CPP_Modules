#include <iostream> // std::cout, std::endl
#include <cstdlib> // EXIT_* MACROS

using std::cout;
using std::endl;

int main(void)
{
    std::string stringOG = "HI THIS IS BRAIN";
    std::string *stringPTR = &stringOG;
    std::string &stringREF = stringOG;

    cout << "Address of stringOG = " << &stringOG << endl;
    cout << "Thru pointer value = " << stringPTR << endl;
    cout << "Thru reference value = " << &stringREF << endl;

    cout << endl;

    cout << "Value of stringOG = " << stringOG << endl;
    cout << "Thru pointer dereferencing = " << *stringPTR << endl;
    cout << "Thru reference = " << stringREF << endl;

    return EXIT_SUCCESS;
}

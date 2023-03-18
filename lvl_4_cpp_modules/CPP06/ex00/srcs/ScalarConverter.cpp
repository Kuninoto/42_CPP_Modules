#include <iostream>
#include <limits>
#include "ScalarConverter.hpp"

using std::cout;
using std::endl;

void ScalarConverter::convert(string literal)
{
    cout << "char: " << as_char(literal) << endl;
    cout << "int: " << as_int(literal) << endl;
    cout << "float: " << as_float(literal) << endl;
    cout << "double: " << as_double(literal) << endl;
}

/* string ScalarConverter::as_char(string& literal)
{
    try {
        return (static_cast<char>(literal));
    }
    catch (const std::exception& e) {
        return ("Impossible");
    }
} */

string ScalarConverter::as_int(string& literal)
{
    try {
        double n = std::stoi(literal);
        return (literal);
    }
    catch (const std::exception& e) {
        return ("Impossible");
    }
}

string ScalarConverter::as_double(string& literal)
{
    try {
        double n = std::stod(literal);
        return (literal);
    }
    catch (const std::exception& e) {
        return ("Impossible");
    }
}

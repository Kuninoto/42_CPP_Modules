#include <iostream>
#include <limits>
#include <sstream>
#include "ScalarConverter.hpp"

using std::cout;
using std::endl;

/* UTILS */

static int ft_stoi(string& str)
{
    int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static bool is_pseudo_literal(string& literal) {
    return (literal == "-inf" || literal == "-inff"
         || literal == "+inf" || literal == "+inff"
         || literal == "nan");
}

void ScalarConverter::convert(string literal)
{
    cout << "char: '" << as_char(literal) << "'" << endl;
    cout << "int: " << as_int(literal) << endl;
//  cout << "float: " << as_float(literal) << endl;
//  cout << "double: " << as_double(literal) << endl;
}

string ScalarConverter::as_char(string& literal)
{
    int decimal_value;

    decimal_value = ft_stoi(literal);
    if (decimal_value < std::numeric_limits<char>::min()
    ||  decimal_value > std::numeric_limits<char>::max())
        return string("impossible");
    if (isprint(decimal_value))
        return string(1, decimal_value);
    else
        return string("Non displayable");
}

string ScalarConverter::as_int(string& literal)
{
    for (size_t i = 0; i < literal.length(); i += 1)
        if (!isdigit(literal.at(i))
        && (literal.at(i) == '+' && literal.at(i) == '-'))
            return string("impossible");
    return string(literal);
}

/*
string ScalarConverter::as_float(string& literal)
{

}
*/

/*
string ScalarConverter::as_double(string& literal)
{

}
*/

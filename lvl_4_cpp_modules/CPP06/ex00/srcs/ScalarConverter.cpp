#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    #ifdef LOGS
        cout << "[ScalarConverter] Default constructor has been called" << endl;
    #endif
}

ScalarConverter::ScalarConverter(const ScalarConverter &to_copy)
{
}

ScalarConverter::~ScalarConverter()
{
    #ifdef LOGS
        cout << "[ScalarConverter] Default destructor has been called" << endl;
    #endif
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &original)
{
    return *this;
}


void ScalarConverter::convert(string literal)
{
    // if (literal == int)
    //      atoi();
}

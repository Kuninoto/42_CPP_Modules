#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include "ScalarConverter.hpp"

using std::cout;
using std::endl;

/* UTILS */

static int ft_stoi(const std::string& str)
{
    int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static float ft_stof(const std::string& str)
{
    float num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

static double ft_stod(const std::string& str)
{
    double num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

enum literal_type {
    error,
    _pseudo_literal,
    _char,
    _int,
    _float,
    _double,
};

static bool is_char(const std::string& literal)
{
    if (literal.length() != 1)
        return false;
    if (literal.at(0) < std::numeric_limits<char>::min()
     || literal.at(0) > std::numeric_limits<char>::max()
     || isdigit(literal.at(0)))
            return false;
    return true;
}

static bool is_int(const std::string& literal)
{
    for (size_t i = literal.at(0) == '-' ? 1 : 0; i < literal.length(); i += 1)
    {
        if (!isdigit(literal.at(i)))
            return false;
    }
    return true;
}

static bool is_float(const std::string& literal)
{
    bool    found_point;

    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return true;
    if (literal.at(literal.length() - 1) != 'f')
        return false;
    found_point = false;
    for (size_t i = 0; i < literal.length() - 1; i += 1)
    {
        if (literal.at(i) == '.' && found_point)
            return false;
        else if (literal.at(i) == '.')
        {
            found_point = true;
            continue;
        }
        if (!isdigit(literal.at(i)))
            return false;
    }
    return true;
}

static bool is_double(const std::string& literal)
{
    bool    found_point;

    found_point = false;
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    for (size_t i = 0; i < literal.length(); i += 1)
    {
        if (literal.at(i) == '.' && found_point)
            return false;
        else if (literal.at(i) == '.')
        {
            found_point = true;
            continue ;
        }
        if (!isdigit(literal.at(i)))
            return false;
    }
    return true;
}

static bool is_pseudo_literal(const std::string& literal) {
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
         || literal == "-inf" || literal == "+inf" || literal == "nan");
}

literal_type get_type(const std::string& literal)
{
    if (is_char(literal))
        return _char;
    if (is_int(literal))
        return _int;
    if (is_float(literal))
       return _float;
    if (is_double(literal))
       return _double;
    return error;
}

void literal_char(char ch)
{
    cout << "char: '" << ch << "'" << endl;
    cout << "int: " << static_cast<int>(ch) << endl;
    cout << "float: " << static_cast<float>(ch) << ".0f" << endl;
    cout << "double: " << static_cast<double>(ch) << ".0" << endl;
}

void literal_int(int nbr)
{
    if (isprint(nbr))
        cout << "char: '" << static_cast<char>(nbr)  << "'" << endl; 
    else
        cout << "char: Non displayable" << endl; 
    cout << "int: " << nbr << endl;
    cout << "float: " << static_cast<float>(nbr) << ".0f" << endl;
    cout << "double: " << static_cast<double>(nbr) << ".0" << endl;
}

static void literal_float(float nbr)
{
    if (isprint(nbr))
        cout << "char: '" << static_cast<char>(nbr) << "'" << endl;
    else
        cout << "char: Non displayable" << endl;
    cout << "int: " << static_cast<int>(nbr) << endl;
    cout << "float: " << nbr << ".0f" << endl;
    cout << "double: " << static_cast<double>(nbr) << ".0" << endl;
}

static void literal_double(double nbr)
{
    if (isprint(nbr))
        cout << "char: '" << static_cast<char>(nbr)  << "'" << endl;
    else
        cout << "char: Non displayable" << endl;
    cout << "int: " << static_cast<int>(nbr) << endl;
    cout << "float: " << static_cast<float>(nbr) << ".0f" << endl;
    cout << "double: " << nbr << ".0" << endl;
}

static void pseudo_literal(literal_type dest_type, const std::string& pseudo_literal)
{
    cout << "char: impossible" << endl;
    cout << "int: impossible" << endl; 
    if (dest_type == _float)
    {
        cout << "float: " << pseudo_literal << endl;
        cout << "double: " << pseudo_literal.substr(0, pseudo_literal.length() - 1) << endl;
    }
    else if (dest_type == _double)
    {
        cout << "float: " << pseudo_literal + "f" << endl;
        cout << "double: " << pseudo_literal << endl;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    switch (get_type(literal))
    {
        case _char:
            literal_char(literal.at(0));
            break;

        case _int:
            literal_int(ft_stoi(literal));
            break;

        case _float:
            if (is_pseudo_literal(literal))
                pseudo_literal(_float, literal);
            else
                literal_float(ft_stof(literal));
            break;

        case _double:
            if (is_pseudo_literal(literal))
                pseudo_literal(_double, literal);
            else
                literal_double(ft_stod(literal));
            break;

        default:
            cout << "WhAt TyPe iS tHaT!? 🤨" << endl;
            break;
    }
}

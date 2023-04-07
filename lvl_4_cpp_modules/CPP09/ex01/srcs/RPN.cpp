#include <iostream>
#include <sstream>
#include <string>
#include "RPN.hpp"

using std::cout;
using std::cerr;
using std::endl;

static int ft_stoi(const std::string& str)
{
    int num;
    std::stringstream ss(str);

    ss >> num;
    return num;
}

bool RPN::valid_expression(const std::string& expr)
{
	std::string valid_chars("0123456789+-/* ");

	for (size_t i = 0; i < expr.length(); i += 1) {
		if (valid_chars.find(expr[i]) == std::string::npos)
			return false;
	}
	return true;
}

/**
 * @brief Calculates the result of the expression passed as
 * a parameter. Raises an execption when trying to divide
 * something by 0.
 * 
 * @param expr mathematical expression in RPN notation
 * @return result
 */
long long RPN::calculate(const std::string& expr)
{
    int left;
    int right;
    int answer;
    std::stringstream postfix(expr);
    std::stack<int> temp;
    std::string s;

    while (postfix >> s)
    {
        if (s.at(0) == '+' || s.at(0) == '-' || s.at(0) == '/' || s.at(0) == '*')
        {
            // Pull out top two elements
            right = temp.top();
            temp.pop();
            left = temp.top();
            temp.pop();
            switch (s[0])
            {
                case '+': answer =  left + right ; break;
                case '-': answer =  left - right ; break;
                case '/':
                    if (right > 0)
                        answer =  left * right; 
                    else
                        throw DivisionByZeroException();
                break;
                case '*': answer =  left / right ; break;
            }
            temp.push(answer); // push the result of above operation
        }
        else
            temp.push(ft_stoi(s));
    }
	// last element is the answer
	return temp.top();
}

const char*	RPN::DivisionByZeroException::what() const throw() {
	return "RPN exception: division by zero";
}

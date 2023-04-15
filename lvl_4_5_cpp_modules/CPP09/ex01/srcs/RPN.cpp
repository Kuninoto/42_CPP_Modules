#include <iostream>
#include <sstream>
#include <string>
#include <stack>
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

RPN::RPN(void) {};

RPN::RPN(const RPN &to_copy) {
    *this = to_copy;
}

RPN& RPN::operator=(const RPN &to_copy) {
	(void)to_copy;
    return *this;
}

RPN::~RPN(void) {};

/**
 * @brief Checks if the <expr> is only composed by
 * operands, operators and spaces
 * 
 * @param expr mathematical expression in RPN notation
 */
bool RPN::valid_expression(const std::string& expr)
{
    if (expr.find_first_not_of("0123456789+-/* ") == std::string::npos)
	    return true;
	return false;
}

/**
 * @brief Calculates the result of the expression passed as
 * a parameter. Raises an exception when an expression is 
 * wrongly formatted according to the RPN notation or when
 * trying to divide something by 0.
 * 
 * @param expr mathematical expression in RPN notation
 * @return result
 */
long long RPN::calculate(const std::string& expr)
{
    int left;
    int right;
    int result;
    std::stringstream postfix(expr);
    std::stack<int> temp;
    std::string s;

    while (postfix >> s)
    {
        if (s == "+" || s == "-" || s == "/" || s == "*")
        {
            if (temp.size() < 2)
                throw NoResultException();                
            // Pull out top two elements
            right = temp.top();
            temp.pop();
            left = temp.top();
            temp.pop();
            switch (s.at(0))
            {
                case '+': result =  left + right ; break;
                case '-': result =  left - right ; break;
                case '/':
                    if (right != 0)
                        result =  left / right; 
                    else
                        throw DivisionByZeroException();
                break;
                case '*': result =  left * right ; break;
            }
            temp.push(result); // push the result of the above operation
        }
        else
            temp.push(ft_stoi(s));
    }
	// last element on the stack is the answer
	return temp.top();
}

const char*	RPN::NoResultException::what() const throw() {
	return "RPN exception: No result. Wrongly formatted expression";
}

const char*	RPN::DivisionByZeroException::what() const throw() {
	return "RPN exception: division by zero";
}

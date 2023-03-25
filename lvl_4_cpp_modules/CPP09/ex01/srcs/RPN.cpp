#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "RPN.hpp"

using std::cout;
using std::endl;

RPN::RPN(void) {};

RPN::RPN(const RPN &to_copy) {
	if (this != &to_copy)
		*this = to_copy;
}

RPN &RPN::operator=(const RPN &to_copy)
{
	if (this == &to_copy)
		return (*this);
	//this->max_size = to_copy.max_size;
	//this->storage = to_copy.storage;
	return (*this);
}

RPN::~RPN(void) {};

bool RPN::valid_expression(string expr)
{
	string valid_chars("0123456789+-/* ");

	for (size_t i = 0; i < expr.length(); i += 1) {
		if (valid_chars.find(expr[i]) == string::npos)
			return false;
	}
	return true;
}

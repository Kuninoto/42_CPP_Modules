#include <cstdlib>
#include <iostream>
#include <string>
#include <iter.hpp>

using std::cout;
using std::endl;

# define ARRAY_LEN 3

int main(void)
{
	int int_array[] = {0, 0, 0};

	cout << "BEFORE plus_one()" << endl;
	::iter(int_array, ARRAY_LEN, &::print_element<int>);


	::iter(int_array, ARRAY_LEN, &::plus_one<int>);


	cout << "AFTER plus_one()" << endl;
	::iter(int_array, ARRAY_LEN, &::print_element<int>);

	return EXIT_SUCCESS;
}

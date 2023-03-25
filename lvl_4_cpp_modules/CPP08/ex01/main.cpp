#include <iostream>
#include <vector>
#include "Span.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	cout << sp.shortestSpan() << endl;
	cout << sp.longestSpan() << endl;

	// EXCEPTIONS

	// Pushing beyond N elements
	// try {
	// 	sp.addNumber(42);
	// }
	// catch(const std::exception& e) {
	// 	cerr << e.what() << '\n';
	// }

	// Trying to get a span with less than 2 elements on the vector
	// Span sp1 = Span(1);
	// sp1.addNumber(1);
	// try {
	// 	cout << sp1.shortestSpan() << endl;
	// }
	// catch(const std::exception& e) {
	// 	cerr << e.what() << '\n';
	// }

	return EXIT_SUCCESS;
}

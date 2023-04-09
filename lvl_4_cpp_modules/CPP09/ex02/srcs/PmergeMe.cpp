#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <ctime>
#include "PmergeMe.hpp"

using std::cout;
using std::cerr;
using std::endl;

# define MICROSECOND 100000

static unsigned int ft_stou(const std::string& str)
{
	unsigned int num;
	std::stringstream ss(str);

	ss >> num;
	return num;
}

PmergeMe::PmergeMe(void) {};

PmergeMe::PmergeMe(const PmergeMe& to_copy) {
    *this = to_copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& to_copy) {
	(void)to_copy;
	return *this;
}

PmergeMe::~PmergeMe(void) {};

void PmergeMe::vecMergeSort(int argc, char **argv)
{
	std::vector<unsigned int> storage;

	for (int i = 1; i < argc; i += 1)
		storage.push_back(ft_stou(argv[i]));

	{
		// print vector storage before sorted
		std::vector<unsigned int>::const_iterator itr;
		cout << "Before: ";
		for (itr = storage.begin(); itr != storage.end(); itr++)
			cout << *itr << " ";
		cout << endl;
	}


	std::clock_t start = std::clock();



	// merge_sort



	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	{
		// print vector storage after sorted
		std::vector<unsigned int>::const_iterator itr;
		cout << "After: ";
		for (itr = storage.begin(); itr != storage.end(); itr++)
			cout << *itr << " ";
		cout << endl;
	}

	cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::vector<unsigned int> : " 
		 << time_taken << " µs" << endl;
}

const char*	PmergeMe::InvalidElementException::what() const throw() {
	return "PmergeMe exception: invalid element";
}

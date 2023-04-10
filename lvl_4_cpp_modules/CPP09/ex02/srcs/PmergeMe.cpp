#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <list>
#include "PmergeMe.hpp"

using std::cout;
using std::endl;

# define MICROSECOND 100000

unsigned int ft_stou(const std::string& str);

PmergeMe::PmergeMe(void) {};

PmergeMe::PmergeMe(const PmergeMe& to_copy) {
    *this = to_copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& to_copy) {
	(void)to_copy;
	return *this;
}

PmergeMe::~PmergeMe(void) {};

static void printVec(std::vector<unsigned int>& vec)
{
	std::vector<unsigned int>::const_iterator itr;
	for (itr = vec.begin(); itr != vec.end(); itr++)
		cout << *itr << " ";
	cout << endl;
}

static std::vector<unsigned int> mergeVecs(std::vector<unsigned int>& left, std::vector<unsigned int>& right)
{
    std::vector<unsigned int> result;

    // Merge the two vectors until one of them becomes empty
    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    // Add any remaining elements from the left vector
    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }

    // Add any remaining elements from the right vector
    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

static std::vector<unsigned int> mergeInsertVec(std::vector<unsigned int>& vec) {
    // Base case: a vector with zero or one elements is already sorted
    if (vec.size() <= 1) {
        return vec;
    }

    // Divide the vector into two halves
    int mid = vec.size() / 2;
    std::vector<unsigned int> left(vec.begin(), vec.begin() + mid);
    std::vector<unsigned int> right(vec.begin() + mid, vec.end());

    // Recursively sort the left and right halves
    left = mergeInsertVec(left);
    right = mergeInsertVec(right);

    // Merge the sorted halves
    return mergeVecs(left, right);
}

void PmergeMe::sortVec(int argc, char **argv)
{
	std::vector<unsigned int> storage;

	for (int i = 1; i < argc; i += 1) {
		storage.push_back(ft_stou(argv[i]));
	}

	cout << "<vec>Before: ";
	printVec(storage);

	std::clock_t start = std::clock();

	storage = mergeInsertVec(storage);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	cout << "<vec>After: ";
	printVec(storage);

	cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::vector<unsigned int> : " 
		 << time_taken << " µs" << endl;
}

static void printList(std::list<unsigned int>& lst)
{
	std::list<unsigned int>::const_iterator itr;
	for (itr = lst.begin(); itr != lst.end(); itr++)
		cout << *itr << " ";
	cout << endl;
}

static std::list<unsigned int> mergeLists(std::list<unsigned int>& left, std::list<unsigned int>& right)
{
    std::list<unsigned int> result;

    // Merge the two vectors until one of them becomes empty
    while (!left.empty() && !right.empty())
	{
        if (left.front() <= right.front())
		{
            result.push_back(left.front());
            left.erase(left.begin());
        }
		else
		{
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }

    // Add any remaining elements from the left vector
    while (!left.empty())
	{
        result.push_back(left.front());
        left.erase(left.begin());
    }

    // Add any remaining elements from the right vector
    while (!right.empty())
	{
        result.push_back(right.front());
        right.erase(right.begin());
    }
    return result;
}

static std::list<unsigned int> mergeInsertList(std::list<unsigned int>& lst) {
    // Base case: a list with zero or one elements is already sorted
    if (lst.size() <= 1) {
        return lst;
    }

    // Divide the list into two halves
    int mid = lst.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;

    for (int i = 0; i < mid; i++) {
        left.push_back(lst.front());
        lst.pop_front();
    }
    right = lst;

    // Recursively sort the left and right halves
    left = mergeInsertList(left);
    right = mergeInsertList(right);

    // Merge the sorted halves
    return mergeLists(left, right);
}

void PmergeMe::sortList(int argc, char **argv)
{
	std::list<unsigned int> storage;

	for (int i = 1; i < argc; i += 1)
		storage.push_back(ft_stou(argv[i]));

    cout << "<list>Before: ";
	printList(storage);

	std::clock_t start = std::clock();

	storage = mergeInsertList(storage);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

    cout << "<list>After: ";
	printList(storage);

	cout << "Time to process a range of " << argc - 1
		 << " elements " << "with std::list<unsigned int> : " 
		 << time_taken << " µs" << endl;
}

const char*	PmergeMe::InvalidElementException::what() const throw() {
	return "PmergeMe exception: invalid element";
}

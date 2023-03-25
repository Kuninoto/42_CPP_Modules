#include "Span.hpp"
#include <exception>
#include <stdexcept>
#include <algorithm>

Span::Span(uint32_t N) : max_size(N), storage(0) {};

Span::Span(const Span &to_copy) {
	if (this != &to_copy)
		*this = to_copy;
}

Span &Span::operator=(const Span &to_copy)
{
	if (this == &to_copy)
		return (*this);
	this->max_size = to_copy.max_size;
	this->storage = to_copy.storage;
	return (*this);
}

Span::~Span(void) {};

void Span::addNumber(int nbr)
{
	if (this->storage.size() == this->max_size)
		throw Span::BeyondMaxSize();
	this->storage.push_back(nbr);
}

int Span::shortestSpan(void)
{
	std::vector<int> v = this->storage;

	if (v.size() < 2) {
		throw Span::NotEnoughElementsException();
	}

	std::sort(v.begin(), v.end());
	int shortest_gap = v.at(1) - v.at(0);

	std::vector<int>::iterator i;
	for (i = v.begin(); i != v.end() - 1; i += 1)
	{
		if (*(i + 1) - *i < shortest_gap)
			shortest_gap = *(i + 1) - *i; 
	}
	return shortest_gap;
}

int Span::longestSpan(void)
{
	std::vector<int> v = this->storage;

	if (v.size() < 2) {
		throw Span::NotEnoughElementsException();
	}

	int min = *std::min_element(v.begin(), v.end());
	int max = *std::max_element(v.begin(), v.end());

	return abs(max - min);
}

char const* Span::BeyondMaxSize::what(void) const throw() {
	return "Beyond vector's max size";
}

char const* Span::NotEnoughElementsException::what(void) const throw() {
	return "Vector must have more than 2 elements";
}

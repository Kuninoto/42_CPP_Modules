#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdint.h>
# include <iostream>
# include <exception>

using std::cout;
using std::endl;

template<typename T>
class Array {
	public:
		Array(void);
		Array(uint32_t n);
		Array(Array& to_copy);
		Array& operator=(Array const& to_copy);
		T&	operator[](uint32_t n) throw(std::exception);
		~Array(void);

		uint32_t size(void);
		class OutOfBoundsException : public std::exception {
			public:
				char const* what(void) const throw();
		};

	private:
		T *storage;
		uint32_t storage_size;
};

template<typename T>
Array<T>::Array(void) : storage(new T[0]()), storage_size(0) {
	#ifdef LOGS
		cout << "[Array] Default Constructor has been called" << endl;
	#endif
}

template<typename T>
Array<T>::Array(uint32_t n) : storage(new T[n]()), storage_size(n) {
	#ifdef LOGS
		cout << "[Array] Parametrized Constructor has been called" << endl;
	#endif
}

template<typename T>
Array<T>::Array(Array& to_copy)
: storage(new T[to_copy.size()]), storage_size(to_copy.size())
{
	*this = to_copy;
	#ifdef LOGS
		cout << "[Array] Copy Constructor has been called" << endl;
	#endif
}

template<typename T>
Array<T>& Array<T>::operator=(Array const& to_copy)
{
	delete[] this->storage;
	this->storage = new T[to_copy.storage_size];
	this->storage_size = to_copy.storage_size;
	for (uint32_t i = 0; i < to_copy.storage_size; i += 1)
		this->storage[i] = to_copy.storage[i];
	#ifdef LOGS
		cout << "[Array] Copy Assignment Operator has been called" << endl;
	#endif
	return *this;
}

template <typename T>
T&	Array<T>::operator[](uint32_t n) throw(std::exception)
{
	if (n >= this->storage_size)
		throw Array<T>::OutOfBoundsException();
	return this->storage[n];
}

template <typename T>
Array<T>::~Array(void) {
	delete[] this->storage;
	#ifdef LOGS
		cout << "[Array] Default Destructor has been called" << endl;
	#endif
}

template<typename T>
uint32_t Array<T>::size(void) {
	return this->storage_size;
}

template <typename T>
char const*	Array<T>::OutOfBoundsException::what(void) const throw() {
	return "Array: Exception: index out of bounds";
}

#endif // ARRAY_HPP
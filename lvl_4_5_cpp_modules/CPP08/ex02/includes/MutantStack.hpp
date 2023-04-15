#ifndef SPAN_HPP
# define SPAN_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack(void);
		MutantStack(const MutantStack &to_copy);
		MutantStack &operator=(const MutantStack& to_copy);
		~MutantStack(void);

		iterator begin(void);
		iterator end(void);
};

template<typename T>
MutantStack<T>::MutantStack(void) {
	#ifdef DEBUG
		cout << "[MutantStack] default constructor called" << endl;
	#endif
};

template<typename T>
MutantStack<T>::MutantStack(MutantStack const& to_copy) {
	*this = to_copy;
	#ifdef DEBUG
		cout << "[MutantStack] copy constructor called" << endl;
	#endif
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& to_copy)
{
	std::stack<int>::operator=(to_copy);
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack(void) {
	#ifdef DEBUG
		cout << "[MutantStack] default destructor called" << endl;
	#endif
};

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
};

#endif // SPAN_HPP
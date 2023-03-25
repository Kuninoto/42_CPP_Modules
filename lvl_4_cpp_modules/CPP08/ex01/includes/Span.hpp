#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdint.h>
# include <string>
# include <exception>
# include <vector>
# include <algorithm>

class Span {
	public:
		Span(uint32_t N);
		Span(const Span &to_copy);
		Span &operator=(const Span& to_copy);
		~Span(void);

		void addNumber(int nbr);
		int shortestSpan(void);
		int longestSpan(void);

		class NotEnoughElementsException : public std::exception {
			public:
				char const* what(void) const throw();
		};
		
		class BeyondMaxSize : public std::exception {
			public:
				char const* what(void) const throw();
		};

	private:
		uint32_t max_size;
		std::vector<int> storage;
		Span();
};

#endif // SPAN_HPP
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <exception>

class PmergeMe {
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& to_copy);
        PmergeMe &operator=(const PmergeMe& to_copy);
        ~PmergeMe(void);

        void sortVec(int argc, char **argv);
        void sortList(int argc, char **argv);

        class InvalidElementException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
};

#endif // PMERGEME_HPP
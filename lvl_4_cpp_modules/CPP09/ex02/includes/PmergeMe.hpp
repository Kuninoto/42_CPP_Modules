#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <exception>

class PmergeMe {
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& to_copy);
        PmergeMe &operator=(const PmergeMe& to_copy);
        ~PmergeMe(void);

        void vecMergeSort(int argc, char **argv);
        // void ?MergeSort(int argc, char **argv);

        class InvalidElementException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
};

#endif // PMERGEME_HPP
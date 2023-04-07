#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <exception>

class RPN {
    public:
        static bool valid_expression(const std::string& expr);
        static long long calculate(const std::string& expr);

        class DivisionByZeroException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };
};

#endif // RPN_HPP
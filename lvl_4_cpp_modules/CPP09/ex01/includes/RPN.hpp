#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class RPN {
    public:
        RPN(void);
        ~RPN(void);

        static bool valid_expression(const std::string& expr);
        static long long calculate(const std::string& expr);
};

#endif // RPN_HPP
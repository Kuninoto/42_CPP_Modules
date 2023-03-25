#ifndef RPN_HPP
# define RPN_HPP

# include <string>
using std::string;

class RPN {
    public:
        RPN(void);
        RPN(const RPN &to_copy);
        RPN &operator=(const RPN& to_copy);
        ~RPN(void);

        bool valid_expression(string expr);
    private:

};

#endif // RPN_HPP
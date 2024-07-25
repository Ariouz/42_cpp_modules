#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <algorithm>
# include <exception>

class RPN
{
    public:
        RPN(const std::string& arg);
        ~RPN();

        

    private:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        std::stack<int> _values;

        int processCalcul(int v1, int v2, const std::string& ope);
};

#endif
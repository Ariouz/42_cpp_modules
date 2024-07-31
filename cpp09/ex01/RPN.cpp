# include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) { (void) other; return *this; }

RPN::RPN(const RPN& other) { (void) other; }

static bool isOperator(const std::string& s, const std::string& ops)
{
    return ops.find(s) != ops.npos;
}

int RPN::processCalcul(int v1, int v2, const std::string& ope)
{
    if (ope == "+")
        this->_values.push(v1+v2);
    else if (ope == "-")
        this->_values.push(v1-v2);
    else if (ope == "/")
    {
        if (v2 == 0)
        {
            std::cout << "Error: Division by 0" << std::endl;
            return 1;
        }
        this->_values.push(v1/v2);
    }
    else
        this->_values.push(v1*v2);
    return 0;
}

RPN::RPN(const std::string& arg)
{
    std::istringstream ss(arg);
    std::string operators = "+-/*";

    std::string s;
    while (std::getline(ss, s, ' '))
    {
        if (isOperator(s, operators))
        {
            if (this->_values.size() < 2)
            {    
                std::cout << "Error: " << s << " should be a number" << std::endl;
                return ;
            }
            int v1 = this->_values.top();
            this->_values.pop();
            int v2 = this->_values.top();
            this->_values.pop();

            if (processCalcul(v2, v1, s) == 1)
                return ;
        }
        else {
            int n;
            std::istringstream iss(s);
            iss >> n;
            if (!iss.eof() || iss.fail())
            {
                std::cout << "Error: invalid value (not a number nor an operator)" << std::endl;
                return ;
            }
            else
                this->_values.push(n);
        }
    }

    if (this->_values.size() != 1) 
    {
        std::cout << "Error: extra or missing value" << std::endl;
        return ;
    }
    std::cout << this->_values.top() << std::endl;
}

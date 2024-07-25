# include "RPN.hpp"
# include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "An argument is expected." << std::endl;
        return (1);
    }

    RPN rpn (argv[1]);
    // std::cout << rpn.eval() << std::endl;
    return (0);
}
#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Please provide 1 argument" << std::endl;
        return (1);
    }
    Harl harl = Harl();
    std::string level = argv[1];
    
    if (!harl.isValidLevel(level))
    {
        std::cout << "Invalid level" << std::endl;
        return (1);
    }

    harl.complain(level);
    return (0);
}
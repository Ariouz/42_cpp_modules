#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    int i = 1;
    while (argv[i])
    {
        for (int j = 0; j < (int) std::strlen(argv[i]); j++)
            std::cout << (char) std::toupper(argv[i][j]);
        std::cout << " ";
        i++;
    }
    std::cout << std::endl;
    return (0);
}
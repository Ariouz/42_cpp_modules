# include "easyfind.hpp"
# include <iostream>
# include <vector>

int main()
{
    std::vector<int> values;
    values.push_back(5);
    values.push_back(7);
    values.push_back(42);
    values.push_back(12);

    std::vector<int>::iterator it = easyfind(values, 42);
    if (it != values.end())
        std::cout << "Found value: " << *it << std::endl;
    else
        std::cout << "Value not found" << std::endl;
    return 0;
}
#include "easyfind.hpp"
# include <vector>

int main()
{
    std::vector<int> values;
    values.push_back(5);
    values.push_back(7);
    values.push_back(42);
    values.push_back(12);

    std::cout << easyfind(values, 12) << std::endl;
    return 0;
}
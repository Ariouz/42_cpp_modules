#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
int easyfind(const T& container, int n)
{
    std::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end()) throw std::exception();
    return *it;
}

#endif
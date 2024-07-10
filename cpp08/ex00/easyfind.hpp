#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <type_traits>
# include <algorithm>

template <typename T>
int easyfind(const T& container, int n)
{
    std::iterator<T> i = std::find(container, n);
    if (i != container.end()) return i;
    throw std::exception();
    return -1;
}

#endif
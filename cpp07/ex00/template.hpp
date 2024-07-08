#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T>
void swap(T& v1, T& v2)
{
    T tmp = v1;
    v1 = v2;
    v2 = tmp;
}

template <typename T>
T min(T& a, T&b)
{
    return a < b ? a : b;
}

template <typename T>
T max(T& a, T&b)
{
   return a > b ? a : b;
}

#endif
#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T>
void iter(T arr[], int len, void func (T&))
{
    for (int i = 0; i < len; i++)
        func(arr[i]);
}

#endif
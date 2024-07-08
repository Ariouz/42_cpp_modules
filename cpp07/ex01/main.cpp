#include <iostream>
#include "template.hpp"

void printElement(int &n)
{
    std::cout << n << std::endl;
}

int main( void ) 
{
    int arr[] = {1, 2, 3, 4, 5};
    ::iter(arr, 5, printElement);
    return 0;
}
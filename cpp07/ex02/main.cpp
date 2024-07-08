#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        std::cout << "--- Copy constructor test ---" << std::endl;
        std::cout << tmp[0] << " == " << numbers[0] << std::endl;
        std::cout << test[0] << " == " << tmp[0] << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    std::cout << "--- Error check 1 ---" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "-> negative index\n";
    }


    std::cout << "--- Error check 2 ---" << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " -> out of bounds\n";
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    std::cout << "--- Print 10 first elements ---" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << numbers[i] << std::endl;
    }

    delete [] mirror;//
    return 0;
}
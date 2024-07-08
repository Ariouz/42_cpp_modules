#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>
class Array
{
    private:
        T *array;
        size_t size;

    public:
        Array() {
            array = new T[];
            size = 0;
        }

        Array(unsigned int n) {
            array = new T[n];
            size = n;
            for (std::size_t index = 0; index < n; index++)
                array[index] = 0;
        }

        Array& operator=(const Array& other)
        {
            if (this == &other) return *this;
            this->array = other.array;
            this->size = other.size;
            return *this;
        }

        Array(const Array& other)
        {
            if (this == &other) return;
            this->array = other.array;
            this->size = other.size;
        }

        ~Array() {};

        T& operator[](std::size_t index)
        {
            if (index >= size) throw std::exception();
            return array[index];
        }

};

#endif
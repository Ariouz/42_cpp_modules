#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
    public:
        Span(const unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        size_t  getMax(void) const;
        int     shortestSpan(void) const;
        int     longestSpan(void) const;

        void    addNumber(int n);
        void    addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        class MaxSizeReachedException : public std::exception 
        {
            public:
                char const* what() const throw ();
        };

        class NotEnoughValuesException : public std::exception 
        {
            public:
                char const* what() const throw ();
        };
    
    private:
        size_t              _max;
        std::vector<int>    _values;
        Span();

};

#endif
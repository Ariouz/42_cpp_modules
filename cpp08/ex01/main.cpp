# include "Span.hpp"
# include <iostream>
# include <vector>
# include <exception>

int main()
{
    std::cout << "Valid span" << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "Max size error =>" << std::endl;
    Span sp2 = Span(2);
    try {
        sp2.addNumber(6);
        sp2.addNumber(3);
        sp2.addNumber(11);
    }catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "Not enough values error =>" << std::endl;
    Span sp3 = Span(2);
    try {
        sp3.addNumber(11);
        std::cout << sp3.shortestSpan() << std::endl;
    }catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::vector<int> vec (1000);
    for (int i = 0; i < 1000; i++) vec[i] = i;

    std::cout << "Valid add range" << std::endl;
    Span sp4 = Span(1000);
    sp4.addRange(vec.begin(), vec.end());
    std::cout << sp4.shortestSpan() << std::endl;
    std::cout << sp4.longestSpan() << std::endl;

    std::cout << "Add range too many values error =>" << std::endl;
    Span sp5 = Span(100);
    try {
        sp5.addRange(vec.begin(), vec.end());
        std::cout << sp5.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
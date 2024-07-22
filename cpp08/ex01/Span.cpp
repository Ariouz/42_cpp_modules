#include "Span.hpp"

Span::Span() {}

Span::Span(const unsigned int N) : _max(N) {}

Span::Span(const Span& other)
{
    if (this == &other) return;
    this->_max = other.getMax();
}

Span& Span::operator=(const Span& other)
{
    if (this == &other) return *this;
    this->_max = other.getMax();
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (this->_values.size() >= this->_max) throw MaxSizeReachedException();
    this->_values.push_back(number);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (this->_values.size() + std::distance(begin, end) > this->_max) throw MaxSizeReachedException();
    this->_values.insert(this->_values.end(), begin, end);
}

int Span::shortestSpan(void) const {
    if (this->_values.size() < 2) throw NotEnoughValuesException();

    std::vector<int> val = this->_values;

    std::sort(val.begin(), val.end());
    int min = val[1] - val[0];
    for (size_t index = 1; index < val.size(); index++)
    {
        if (val[index] - val[index - 1] < min)
            min = val[index] - val[index - 1];
    }
    return min;
}

int Span::longestSpan(void) const {
    std::vector<int> val = this->_values;
    return *std::max_element(val.begin(), val.end()) - *std::min_element(val.begin(), val.end());
}

size_t Span::getMax(void) const
{
    return this->_max;
}

const char* Span::MaxSizeReachedException::what(void) const throw() {
    return "Max size reached";
}

const char* Span::NotEnoughValuesException::what(void) const throw() {
    return "not enough values in span";
}
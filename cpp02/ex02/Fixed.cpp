#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
}

Fixed::Fixed(const int n)
{
    this->value = n << this->bits;
}

Fixed::Fixed(const float n)
{
    this->value = roundf(n * (1 << this->bits));
}

Fixed::Fixed(const Fixed& fixed)
{
    *this = fixed;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->value = other.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->value <= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return (Fixed(toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed res = *this;
    this->value++;
    return res;
}

Fixed Fixed::operator--(int)
{
    Fixed res = *this;
    this->value--;
    return res;
}

Fixed& Fixed::min(Fixed& a, Fixed&b)
{
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed&b)
{
    return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed&b)
{
    return a.value < b.value ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed&b)
{
    return a.value > b.value ? a : b;
}

int Fixed::getRawBits() const
{
    return this->value;
}

void Fixed::setRawBits(const int raw)
{
    this->value = raw;
}

float Fixed::toFloat() const
{
    return (float) this->value / (1 << this->bits);
}

int Fixed::toInt() const
{
    return this->value >> this->bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fix)
{
    out << fix.toFloat();
    return (out);
}
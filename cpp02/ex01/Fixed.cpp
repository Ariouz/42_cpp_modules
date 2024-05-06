#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    this->value = n << this->bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n)
{
    this->value = roundf(n * (1 << this->bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
    *this = fixed;
    std::cout << "Copy construcutor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &fixed)
        this->value = fixed.getRawBits();
    return (*this);
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
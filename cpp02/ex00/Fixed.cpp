#include "Fixed.hpp"

Fixed::Fixed()
{
    this->value = 0;
    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy construcutor called" << std::endl;
    *this = fixed;
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
    std::cout << "getRawbits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(const int raw)
{
    this->value = raw;
}
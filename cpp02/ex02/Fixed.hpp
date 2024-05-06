#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed(const int n);
        Fixed(const float n);
        ~Fixed();
        Fixed& operator=(const Fixed& other);

        int getRawBits() const;
        void setRawBits(const int raw);
        float toFloat() const;
        int toInt() const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator--();
        Fixed& operator++();
        Fixed operator++(int);
        Fixed operator--(int);

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        static Fixed& min(Fixed& a, Fixed&b);
        static Fixed& max(Fixed& a, Fixed&b);
        static const Fixed& min(const Fixed& a, const Fixed&b);
        static const Fixed& max(const Fixed& a, const Fixed&b);

    private:
        int value;
        static const int bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fix);

#endif
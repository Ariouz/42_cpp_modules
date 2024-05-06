#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed& fixed);
        Fixed& operator=(const Fixed& fixed);
        Fixed(const int n);
        Fixed(const float n);
        ~Fixed();

        int getRawBits() const;
        void setRawBits(const int raw);
        float toFloat() const;
        int toInt() const;

    private:
        int value;
        static const int bits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fix);

#endif